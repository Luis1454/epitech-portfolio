
import socket
import threading
import sys
from parse import parse_dimension, parse_look, parse_inventory, parse_broadcast
from function import take_item, check_tile, check_players, get_direction, find_direction, get_item_nb, move, move_join_3, move_join_4, logic_ia

class ZappyAI:
    def __init__(self, host, port, name):
        self.host = host
        self.port = port
        self.name = name
        self.sock = None
        self.buf_size = 4096
        self.requests = []
        self.lock = threading.Lock()
        self.running = True
        self.world_width = None
        self.world_height = None
        self.level = 1
        self.look_data = []
        self.inventory = {}
        self.change_dir = 0
        self.have_linemate = 0
        self.have_deraumere = 0
        self.have_sibur = 0
        self.have_phiras = 0
        self.level_up = False
        self.set_object = 0
        self.msg_nb = None
        self.msg_txt = None
        self.index = 0
        self.index_join = 0
        self.index_max = 8
        self.connect_nb = 1
        self.fork = False
        self.exec = False
        self.join = 0
        self.join_player = False
        self.find = False
        self.send_find = True
        self.wait = False
        self.item = "Food"
        self.all = False
        self.to_wait = False
        self.count_turn = 0

    #fonction qui permet de se connecter au serveur, d'envoyer le nom de la team et de recevoire le client number et les dimension de la map
    def connect(self):
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.connect((self.host, self.port))
            print(f"Connected to {self.host}:{self.port}")

            welcome_msg = self.sock.recv(self.buf_size).decode('utf-8').strip()
            print(f"Received: {welcome_msg}")
            if welcome_msg == "WELCOME":
                # Sending the team name
                team_name_message = f"{self.name}\n"
                self.sock.sendall(team_name_message.encode('utf-8'))
                print(f"Sent {team_name_message.strip()}")

                # Receiving the client number and world dimensions
                response = self.sock.recv(self.buf_size).decode('utf-8').strip()
                if response == "ko":
                    print("too many client in the same team")
                    self.sock.close()
                    return False
                parts = response.split('\n')
                client_num = parts[0].strip()
                world_dimensions = parts[1].strip() if len(parts) > 1 else None

                print(f"Client Number: {client_num}")
                if world_dimensions:
                    parse_dimension(self, world_dimensions)
                    print(f"World Dimensions: width={self.world_width}, height={self.world_height}")
                else:
                    print("World dimensions not received.")
                return True
            else:
                print("Unexpected welcome message:", welcome_msg)
                self.sock.close()
                return False
        except Exception as e:
            print(f"Connection error: {e}")
            return False

    #fonction qui permet d'envoyer une requête au serveur
    def send_request(self, request):
        with self.lock:
            if len(self.requests) < 10:
                try:
                    message = f"{request}\n"
                    self.sock.sendall(message.encode('utf-8'))
                    print(f"Sent request: {message.strip()}")
                    self.requests.append(request)
                    self.exec = True
                    if request == "Incantation":
                        self.level_up = True
                    if request == "Fork":
                        self.fork = True
                except Exception as e:
                    print(f"Send request error: {e}")
                    self.running = False
            else:
                print("Too many requests in the queue. Waiting for server response.")

    #fonction qui permet de recevoire les reponses du serveur
    def receive_response(self):
        try:
            while self.running:
                response = self.sock.recv(self.buf_size).decode('utf-8').strip()
                if not response or response == "dead":
                    print("Server closed the connection.")
                    self.running = False
                    break

                print("Server Response:", response)
                if response.startswith("Elevation") == False and response.startswith("message") == False and response.startswith("eject:") == False and response != ("Inventory") and response != ("Look") and response != ("Connect_nbr"):
                    self.exec = False

                if response.startswith("message"):
                    try:
                        parse_broadcast(self, response)
                        if self.msg_txt == "pomme" and self.level == 2 and self.get_item_nb("food") > 10:
                            self.to_wait = True
                        if self.msg_txt == "carotte" and self.level == 3 and self.get_item_nb("food") > 10:
                            self.to_wait = True
                            print("\nwait 2\n")
                        if self.msg_txt == "fraise" and self.level == 2:
                            self.find = True
                            self.wait = False
                    except ValueError as e:
                        print(f"Error parsing broadcast message: {e}")
                
                if response.startswith("Current") or response == "ko":
                    self.level_up = False
                    self.level += 1

                with self.lock:
                    if self.requests:
                        last_request = self.requests.pop(0)
                        if last_request == "Look" and response != "ok" and response != "ko" and response.startswith("message") == False and response.startswith("eject:") == False:
                            parse_look(self, response)
                            self.exec = False
                        if last_request == "Inventory" and response != "ok" and response != "ko" and response.startswith("message") == False and response.startswith("eject:") == False:
                            parse_inventory(self, response)
                            self.exec = False
                        if last_request == "Take linemate" and response == "ok":
                            self.have_linemate += 1
                        if last_request == "Take deraumere" and response == "ok":
                            self.have_deraumere += 1
                        if last_request == "Take sibur" and response == "ok":
                            self.have_sibur += 1
                        if last_request == "Take phiras" and response == "ok":
                            self.have_phiras += 1
                        if last_request == "Set linemate" and response == "ok":
                            self.have_linemate -= 1
                        if last_request == "Set deraumere" and response == "ok":
                            self.have_deraumere -= 1
                        if last_request == "Set sibur" and response == "ok":
                            self.have_sibur -= 1
                        if last_request == "Set phiras" and response == "ok":
                            self.have_phiras -= 1
                        if last_request == "Connect_nbr" and response != "ok" and response != "ko" and response.startswith("[") == False and response.startswith("message") == False and response.startswith("eject:") == False:
                            self.connect_nb = int(response)
                            self.exec = False
                        if last_request == "Incantation" and response == "ko":
                            self.level_up == False

        except ConnectionResetError:
            print("Connection with server was closed unexpectedly.")
            self.running = False
        except Exception as e:
            print(f"Receive response error: {e}")
            self.running = False

    def take_item(self):
        return take_item(self)

    def check_tile(self, object):
        return check_tile(self, object)
    
    def check_players(self):
        return check_players(self)

    def get_direction(self, item):
        return get_direction(self, item)

    def find_direction(self, item):
        return find_direction(self, item)

    def get_item_nb(self, item):
        return get_item_nb(self, item)

    def move(self):
        return move(self)

    def move_join_3(self):
        return move_join_3(self)

    def move_join_4(self):
        return move_join_4(self)

    def logic_ia(self):
        return logic_ia(self)

    def run(self):
        if not self.connect():
            return

        response_thread = threading.Thread(target=self.receive_response, daemon=True)
        response_thread.start()

        try:
            self.logic_ia()
        except KeyboardInterrupt:
            print("Interrupted by user")
            self.running = False
            sys.exit(2)

        response_thread.join()

        if self.sock:
            self.sock.close()