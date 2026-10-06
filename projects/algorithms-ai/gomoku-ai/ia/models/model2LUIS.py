class GomokuAI:
    def __init__(self, size=20):
        self.size = size
        self.board = [[0 for _ in range(size)] for _ in range(size)]
        self.max_depth = 2
        self.directions = [(0, 1), (1, 0), (1, 1), (1, -1)]
        self.move_cache = set()
        self.transposition_table = {}

        self._adjacent_offsets = []
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                if dx != 0 or dy != 0:
                    self._adjacent_offsets.append((dx, dy))

    def _iter_adjacent_positions(self, pos):
        x, y = pos
        for dx, dy in self._adjacent_offsets:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.size and 0 <= ny < self.size:
                yield nx, ny

    def _iter_occupied_positions(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] != 0:
                    yield i, j

    def get_valid_moves(self):
        if not self.move_cache:
            moves = set()
            for i, j in self._iter_occupied_positions():
                for ni, nj in self._iter_adjacent_positions((i, j)):
                    if self.board[ni][nj] == 0:
                        moves.add((ni, nj))

            if not moves:
                center = self.size // 2
                moves.add((center, center))

            self.move_cache = moves
        return list(self.move_cache)

    def _count_line(self, x, y, dx, dy, player):
        """Compte le nombre de pièces consécutives dans une direction."""
        count = 1
        spaces = 0
        blocks = 0

        # Vérifier dans les deux directions
        for direction in (-1, 1):
            for step in range(1, 5):
                nx, ny = x + direction * dx * step, y + direction * dy * step
                if not (0 <= nx < self.size and 0 <= ny < self.size):
                    blocks += 1
                    break
                
                cell = self.board[nx][ny]
                if cell == 0:
                    spaces += 1
                    break
                if cell != player:
                    blocks += 1
                    break
                count += 1

        return count, spaces, blocks

    def find_winning_move(self):
        """Cherche un coup gagnant immédiat pour l'IA."""
        valid_moves = self.get_valid_moves()
        for x, y in valid_moves:
            self.board[x][y] = 1
            if self._check_win_at(x, y, 1):
                self.board[x][y] = 0
                return (x, y)
            self.board[x][y] = 0
        return None

    def find_blocking_move(self):
        """Cherche un coup pour bloquer l'adversaire, en priorité les plus longues séquences."""
        threats = []  # Liste des menaces [(longueur, x, y)]
        valid_moves = self.get_valid_moves()
        
        for x, y in valid_moves:
            max_length = 0
            for dx, dy in self.directions:
                self.board[x][y] = -1  # Simuler un coup adverse
                count, spaces, blocks = self._count_line(x, y, dx, dy, -1)
                self.board[x][y] = 0
                
                # Évaluer la menace
                if count >= 4 or (count == 3 and spaces == 2 and blocks == 0):
                    max_length = max(max_length, count)
                    
            if max_length > 0:
                threats.append((max_length, x, y))
        
        # Trier par longueur décroissante
        threats.sort(reverse=True)
        return threats[0][1:] if threats else None

    def _check_win_at(self, x, y, player):
        """Vérifie si un coup à (x,y) est gagnant."""
        for dx, dy in self.directions:
            count, _, _ = self._count_line(x, y, dx, dy, player)
            if count >= 5:
                return True
        return False

    def get_best_move(self):
        """Obtient le meilleur coup en suivant la priorité :
        1. Gagner si possible
        2. Bloquer une menace adverse
        3. Jouer stratégiquement avec minmax"""
        
        # 1. Vérifier d'abord si on peut gagner
        winning_move = self.find_winning_move()
        if winning_move:
            return winning_move
        
        # 2. Vérifier s'il faut bloquer l'adversaire
        blocking_move = self.find_blocking_move()
        if blocking_move:
            return blocking_move
        
        # 3. Sinon, utiliser minmax pour un coup stratégique
        _, best_move = self.minmax(self.max_depth, float('-inf'), float('inf'), True)
        return best_move

    def minmax(self, depth, alpha, beta, maximizing):
        """Version simplifiée de minmax qui s'arrête si une situation critique est trouvée."""
        if depth == 0:
            return self.evaluate_position(), None

        valid_moves = self.get_valid_moves()
        if not valid_moves:
            return 0, None

        best_move = None
        best_eval = float('-inf') if maximizing else float('inf')

        for move in valid_moves:
            x, y = move
            self.board[x][y] = 1 if maximizing else -1
            
            # Vérifier rapidement si ce coup est décisif
            if self._check_win_at(x, y, 1 if maximizing else -1):
                eval_score = float('inf') if maximizing else float('-inf')
            else:
                eval_score, _ = self.minmax(depth - 1, alpha, beta, not maximizing)
            
            self.board[x][y] = 0

            if maximizing and eval_score > best_eval:
                best_eval, best_move = eval_score, move
                alpha = max(alpha, eval_score)
            elif not maximizing and eval_score < best_eval:
                best_eval, best_move = eval_score, move
                beta = min(beta, eval_score)

            if beta <= alpha:
                break

        return best_eval, best_move

    def evaluate_position(self):
        """Évaluation simplifiée qui se concentre sur les menaces immédiates."""
        score = 0
        for i, j in self._iter_occupied_positions():
            player = self.board[i][j]
            for dx, dy in self.directions:
                count, spaces, blocks = self._count_line(i, j, dx, dy, player)
                
                # Calcul du score basé sur la longueur et l'ouverture
                if count >= 5:
                    return 1000000 if player == 1 else -1000000
                elif count == 4:
                    if blocks == 0:
                        score += 50000 if player == 1 else -100000
                    elif blocks == 1:
                        score += 1000 if player == 1 else -2000
                elif count == 3 and blocks == 0:
                    score += 500 if player == 1 else -1000
                elif count == 2 and blocks == 0:
                    score += 50 if player == 1 else -100

        return score

    def make_move(self, x, y, player):
        if 0 <= x < self.size and 0 <= y < self.size and self.board[x][y] == 0:
            self.board[x][y] = player
            self.move_cache.clear()
            return True
        return False

    def check_winner(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] != 0:
                    player = self.board[i][j]
                    for dx, dy in self.directions:
                        count, _, _ = self._count_line(i, j, dx, dy, player)
                        if count >= 5:
                            return player
        return 0

    def display_board(self):
        red = "\033[91m"
        green = "\033[92m"
        clear = "\033[0m"
        piece1 = "● "
        piece2 = "○ "
        print("  " + "-" * 42)
        for i in range(self.size):
            print(f"{i:2d}|", end="")
            for j in range(self.size):
                if self.board[i][j] == 1:
                    print(green + piece1, end="")
                elif self.board[i][j] == -1:
                    print(red + piece2, end="")
                else:
                    print(clear + "  ", end="")
            print("|")

def play_game():
    """Lance une partie de Gomoku."""
    import time

    game = GomokuAI()
    current_player = 1
    total_moves = 0
    total_time = 0

    while True:
        start_time = time.time()
        best_move = game.get_best_move()
        end_time = time.time()

        move_time = (end_time - start_time) * 1000
        total_time += move_time
        total_moves += 1

        if current_player == 1:
            game.make_move(best_move[0], best_move[1], current_player)
            game.display_board()
            print(f"L'IA {current_player} joue en {best_move} - Temps: {move_time:.2f}ms")
        elif current_player == -1:
            x, y = map(int, input("Entrez la position (x, y) : ").split())
            # game.make_move(best_move[0], best_move[1], current_player)
            game.make_move(x, y, current_player)
            game.display_board()

        current_player = -current_player
        winner = game.check_winner()
        if winner != 0:
            avg_time = total_time / total_moves
            print(f"\nVictoire du joueur {winner}!")
            print(f"Temps moyen par coup: {avg_time:.2f}ms")
            print(f"Nombre total de coups: {total_moves}")
            break


if __name__ == "__main__":
    play_game()