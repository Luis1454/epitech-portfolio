
#fonction qui parse les dimensions de la map
def parse_dimension(self, dimension_str):
    dimensions = dimension_str.strip().split()
    if len(dimensions) == 2:
        self.world_width = int(dimensions[0])
        self.world_height = int(dimensions[1])

#fonction qui parse le resultat de la commande Look
def parse_look(self, look_str):
    try:
        look_str = look_str.strip().strip('[]').strip()
        if not look_str:
            self.look_data = []
            return
        
        tiles = look_str.split(',')
        parsed_tiles = [tile.strip().split() for tile in tiles]
        self.look_data = parsed_tiles
    except Exception as e:
        print(f"Look parse error: {e}")
        self.look_data = []

#fonction qui parse le contenu de l'inventaire
def parse_inventory(self, inventory_str):
    try:
        items = inventory_str.strip().strip('[]').split(',')
        self.inventory = {}
        for item in items:
            item = item.strip()
            if not item:
                continue
            try:
                parts = item.split()
                if len(parts) != 2:
                    raise ValueError(f"Invalid item format: {item}")
                name, nb = parts
                self.inventory[name] = int(nb)
            except ValueError as ve:
                print(f"Invalid item format: {item} ({ve})")
    except Exception as e:
        print(f"An error occurred while parsing inventory: {e}")

#fonction qui parse un message recu d'un broadcast
def parse_broadcast(self, msg_str):
    parts = msg_str.split(',', 1)
    msg_prefix = parts[0].strip()
    self.msg_txt = parts[1].strip()

    prefix_parts = msg_prefix.split()
    self.msg_nb = int(prefix_parts[1])