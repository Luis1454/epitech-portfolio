
import time

#fonction qui permet de prendre le première item disponible sur notre case 
def take_item(self):
    for item in self.look_data[0]:
        if item != "player":
            self.send_request(f"Take {item}")
            break

#fonction qui renvoie le nombre d'un item demander sur la case
def check_tile(self, object):
    return self.look_data[0].count(object)

#fonction qui renvoie True si il y a un player dans le champ de vision du player
def check_players(self):
    for i in range(1, len(self.look_data)):
        if "player" in self.look_data[i]:
            return True
    return False

#fonction pour trouver la direction d'un item dans la fonction find_direction
def get_direction(self, item):
    if len(self.look_data) > 2 and item in self.look_data[2]:
        return 2
    for i in range(1, len(self.look_data)):
        if item in self.look_data[i]:
            return i
    return 0

#fonction pour se deplacer vers un item
def find_direction(self, item):
    n = self.get_direction(item)
    if n == 1 or n == 4 or n == 5 or n == 9 or n == 10 or n == 11:
        self.send_request("Left")
        self.change_dir = 1
    elif n == 2 or n == 6 or n == 12:
        self.send_request("Forward")
        self.change_dir = 2
    elif n == 3 or n == 7 or n == 8 or n == 13 or n == 14 or n == 15:
        self.send_request("Right")
        self.change_dir = 3
    else:
        self.send_request("Forward")
        self.change_dir = 0

def get_item_nb(self, item):
    return self.inventory.get(item, 0)

#boucle pour rejoindre un autre joueur et passer au level 3
def move_join_4(self):
    #incantation en cours
    if self.level_up or self.exec:
        return

    if self.index_join == 0 and self.find == False:
        self.find_direction("player")
    elif self.index_join == 1:
        if self.have_linemate == 2 and self.have_sibur == 1 and self.have_phiras == 2 and self.level == 3 and self.find and self.all == True:
            self.send_request("Set linemate")
            self.set_object += 1
        elif self.level == 3 and self.find and self.all == False:
            self.send_request("Right")
        elif (self.change_dir == 1 or self.change_dir == 3) and self.find == False:
            self.send_request("Forward")
        else:
            self.send_request("Look")
    elif self.index_join == 2:
        if self.have_lineamte == 1 and self.have_sibur == 1 and self.have_phiras == 2 and self.level == 3 and self.set_object == 1 and self.find and self.all == True:
            self.send_request("Set linemate")
            self.set_object += 1
        elif self.level == 3 and self.find and self.all == False:
            self.send_request("Right")
        elif self.change_dir == 1:
            self.send_request("Right")
        elif self.change_dir == 3:
            self.send_request("Left")
        elif self.change_dir == 2:
            self.send_request("Look")
            self.change_dir = 0
    elif self.index_join == 3:
        if self.have_sibur == 1  and self.have_phiras == 2 and self.level == 3 and self.set_object == 2 and self.find and self.all == True:
            self.send_request("Set sibur")
            self.set_object += 1
        elif self.level == 3 and self.find and self.all == False:
            self.send_request("Right")
        elif (self.change_dir == 1 or self.change_dir == 3) and self.find == False:
            self.send_request("Forward")
        elif self.look_data and self.check_tile("food") >= 1:
            self.send_request("Take food")
    elif self.index_join == 4:
        if self.have_phiras == 2 and self.level == 3 and self.set_object == 3 and self.find and self.all == True:
            self.send_request("Set sibur")
            self.set_object += 1
        elif self.level == 3 and self.find and self.all == False:
            self.send_request("Right")
    elif self.index_join == 5:
        if self.have_phiras == 1 and self.level == 3 and self.set_object == 4 and self.find and self.all == True:
            self.send_request("Set sibur")
            self.set_object += 1
        elif self.level == 3 and self.find and self.all == False:
            self.send_request("Right")
    elif self.index_join == 6:
        if (self.set_object == 5 or self.all == False) and self.level == 3 and self.find:
            self.send_request("Incantation")
            self.level_up = True
            self.set_object = 0
            self.find = False
            self.join_player = False
            self.all = False
    elif self.index_join == 7:
        self.send_request("Look")
    elif self.index_join == 8:
        if self.check_tile("player") >= 2 and self.send_find and self.level == 2:
            # fraise signifie find, indique a l'autre player qu'ils sont sur la meme case et qu'il peuvent commencer l'incantation
            self.send_request("Broadcast fraise")
            self.find = True
            self.send_find = False
        
    self.index_join += 1
    if self.index_join > 8:
        self.index_join = 0

#boucle pour rejoindre un autre joueur et passer au level 3
def move_join_3(self):
    #incantation en cours
    if self.level_up or self.exec:
        return

    if self.index_join == 0 and self.find == False:
        self.find_direction("player")
    elif self.index_join == 1:
        if self.have_linemate == 1 and self.have_deraumere == 1 and self.have_sibur == 1 and self.level == 2 and self.find and self.all == True:
            self.send_request("Set linemate")
            self.set_object += 1
        elif self.level == 2 and self.find and self.all == False:
            self.send_request("Right")
        elif (self.change_dir == 1 or self.change_dir == 3) and self.find == False:
            self.send_request("Forward")
        else:
            self.send_request("Look")
    elif self.index_join == 2:
        if self.have_deraumere == 1 and self.have_sibur == 1 and self.level == 2 and self.set_object == 1 and self.find and self.all == True:
            self.send_request("Set deraumere")
            self.set_object += 1
        elif self.level == 2 and self.find and self.all == False:
            self.send_request("Right")
        elif self.change_dir == 1:
            self.send_request("Right")
        elif self.change_dir == 3:
            self.send_request("Left")
        elif self.change_dir == 2:
            self.send_request("Look")
            self.change_dir = 0
    elif self.index_join == 3:
        if self.have_sibur == 1 and self.level == 2 and self.set_object == 2 and self.find and self.all == True:
            self.send_request("Set sibur")
            self.set_object += 1
        elif self.level == 2 and self.find and self.all == False:
            self.send_request("Right")
        elif (self.change_dir == 1 or self.change_dir == 3) and self.find == False:
            self.send_request("Forward")
        elif self.look_data and self.check_tile("food") >= 1:
            self.send_request("Take food")
    elif self.index_join == 4:
        if (self.set_object == 3 or self.all == False) and self.level == 2 and self.find:
            self.send_request("Incantation")
            self.level_up = True
            self.set_object = 0
            self.find = False
            self.join_player = False
            self.all = False
    elif self.index_join == 5:
        self.send_request("Look")
    elif self.index_join == 6:
        if self.check_tile("player") >= 2 and self.send_find and self.level == 2:
            # fraise signifie find, indique a l'autre player qu'ils sont sur la meme case et qu'il peuvent commencer l'incantation
            self.send_request("Broadcast fraise")
            self.find = True
            self.send_find = False
        
    self.index_join += 1
    if self.index_join > 6:
        self.index_join = 0

#boucle principale pour rechercher de la nourriture et des item, et passe level 2
def move(self):
    if self.level_up or self.exec or self.wait:
        return

    if self.index == 0 and self.find == False:
        if self.check_players() and self.have_linemate == 1 and self.have_deraumere == 1 and self.have_sibur == 1 and self.level == 2:
            self.index = 5
        elif self.check_players() and self.have_linemate >= 2 and self.have_sibur >= 1 and self.have_phiras >= 2 and self.level == 3:
            self.index = 5
        elif self.look_data and self.check_tile("thystame") >= 1:
            self.send_request("Take thystame")
        elif self.look_data and self.check_tile("linemate") >= 1 and self.have_linemate < 2:
            self.send_request("Take linemate")
        elif self.look_data and self.check_tile("deraumere") >= 1 and self.have_deraumere < 1 and self.level == 2:
            self.send_request("Take deraumere")
        elif self.look_data and self.check_tile("sibur") >= 1 and self.have_sibur < 1 and self.level == 2:
            self.send_request("Take sibur")
        elif self.look_data and self.check_tile("phiras") >= 1 and self.have_phiras < 2 and self.level == 3:
            self.send_request("Take phiras")
        elif (self.change_dir == 1 or self.change_dir == 3) and self.check_tile(self.item) >= 1:
            self.send_request(f"Take {self.item}")
            self.change_dir = 0
            self.item = "food"
        elif self.get_item_nb("food") >= 15 and self.get_item_nb("linemate") < 1:
            self.find_direction("linemate")
            self.item = "linemate"
        elif self.get_item_nb("food") >= 15 and self.get_item_nb("sibur") < 1:
            self.find_direction("sibur")
            self.item = "sibur"
        elif self.get_item_nb("food") >= 20 and self.get_item_nb("linemate") > 1 and self.get_item_nb("sibur") > 1:
            self.find_direction("thystame")
            self.item = "thystame"
        else:
            self.find_direction("food")
            self.item = "food"
    elif self.index == 1:
        if self.have_linemate == 1 and self.level == 1:
            self.send_request("Inventory")
            time.sleep(0.1)
            if self.get_item_nb("food") > 4:
                self.send_request("Set linemate")
                self.set_object += 1
        elif (self.change_dir == 1 or self.change_dir == 3) and self.find == False:
            self.send_request("Forward")
        elif self.change_dir == 2:
            self.send_request(f"Take {self.item}")
            self.change_dir = 0
            self.item = "food"
        else:
            self.send_request("Look")
    elif self.index == 2:
        if self.check_players() and self.have_linemate == 1 and self.have_deraumere == 1 and self.have_sibur == 1 and self.level == 2:
            self.index = 5
        elif self.check_players() and self.have_linemate >= 2 and self.have_sibur >= 1 and self.have_phiras >= 2 and self.level == 3:
            self.index = 5
        elif self.level == 1 and self.set_object == 1 and self.level == 1:
            self.send_request("Incantation")
            self.level_up = True
            self.set_object = 0
        elif self.change_dir == 1:
            self.send_request("Right")
        elif self.change_dir == 3:
            self.send_request("Left")
        elif self.change_dir == 2:
            self.send_request("Look")
            self.change_dir = 0
    elif self.index == 3:
        if self.change_dir == 1 or self.change_dir == 3:
            self.send_request("Forward")
        elif self.look_data and self.check_tile("food") >= 1:
            self.send_request("Take food")
    elif self.index == 4:
        if self.connect_nb <= 0 and self.fork == False:
            self.send_request("Fork")
        elif self.find == False:
            self.send_request("Connect_nbr")
        if self.connect_nb > 0:
            self.fork == False
    elif self.index == 5:
        self.send_request("Inventory")
    elif self.index == 6:
        if self.check_players() and self.have_linemate == 1 and self.have_deraumere == 1 and self.have_sibur == 1 and self.level == 2:
            # pomme signifie wait, demande a un autre player de l'attendre pour passer level 3
            self.send_request("Broadcast pomme")
            self.join_player = True
            self.all = True
        elif self.check_players() and self.have_linemate >= 2 and self.have_sibur >= 1 and self.have_phiras >= 2 and self.level == 3:
            # carotte signifie wait, demande a un autre player de l'attendre pour passer level 4
            self.send_request("Broadcast carotte")
            self.join_player = True
            self.all = True
    elif self.index == 7:
        self.send_request("Look")
    elif self.index == 8:
        if (self.check_tile("egg") >= 1 or self.check_tile("player") >= 5) and self.find == False:
            self.send_request("Eject")
    elif self.index == 9:
        if self.to_wait:
            self.wait = True
            self.to_wait = False
        
    self.index += 1
    if self.index > 9:
        self.index = 0

def logic_ia(self):
    while self.running:
        if len(self.requests) < 10 and not self.level_up:
            if (self.join_player or self.find) and self.level == 2:
                self.move_join_3()
            elif (self.join_player or self.find) and self.level == 3:
                self.move_join_4()
            elif self.wait == False:
                self.move()
        else:
            time.sleep(0.5)
