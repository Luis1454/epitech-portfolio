class GomokuAI:
    def __init__(self, size=20):
        self.size = size
        self.board = [[0 for _ in range(size)] for _ in range(size)]
        self.max_depth = 3
        self.directions = [(0, 1), (1, 0), (1, 1), (1, -1)]
        self.move_cache = set()
        self.transposition_table = {}

        # Pré-calculer les positions adjacentes possibles
        self._adjacent_offsets = []
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                if dx != 0 or dy != 0:
                    self._adjacent_offsets.append((dx, dy))

    def _iter_adjacent_positions(self, pos):
        """Générateur pour itérer sur les positions adjacentes."""
        x, y = pos
        for dx, dy in self._adjacent_offsets:
            nx, ny = x + dx, y + dy
            if 0 <= nx < self.size and 0 <= ny < self.size:
                yield nx, ny

    def _iter_occupied_positions(self):
        """Itérateur pour les positions occupées."""
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] != 0:
                    yield i, j

    def get_valid_moves(self):
        """Retourne les positions valides."""
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

    def _evaluate_line(self, x, y, dx, dy, player):
        """Évalue une ligne de jeu."""
        count = 1
        blocked_ends = 0

        for direction in (-1, 1):
            for step in range(1, 5):
                nx, ny = x + direction * dx * step, y + direction * dy * step
                if not (0 <= nx < self.size and 0 <= ny < self.size):
                    blocked_ends += 1
                    break
                cell = self.board[nx][ny]
                if cell != player:
                    if cell != 0:
                        blocked_ends += 1
                    break
                count += 1

        if count >= 5:
            return 1000000 if player == 1 else -1000000
        scores = [0, 0, 100, 1000, 10000]
        base_score = scores[min(count, 4)]
        return (base_score if player == 1 else -base_score) >> blocked_ends

    def evaluate_position(self):
        """Évalue la position actuelle du plateau."""
        board_hash = str(self.board)  # Version simplifiée du hachage
        if board_hash in self.transposition_table:
            return self.transposition_table[board_hash]

        score = 0
        for i, j in self._iter_occupied_positions():
            player = self.board[i][j]
            for dx, dy in self.directions:
                score += self._evaluate_line(i, j, dx, dy, player)

        self.transposition_table[board_hash] = score
        return score

    def minmax(self, depth, alpha, beta, maximizing):
        """Algorithme MinMax avec élagage alpha-beta."""
        board_hash = str(self.board)
        if depth != self.max_depth and board_hash in self.transposition_table:
            return self.transposition_table[board_hash], None

        if depth == 0:
            eval_score = self.evaluate_position()
            self.transposition_table[board_hash] = eval_score
            return eval_score, None

        valid_moves = self.get_valid_moves()
        if not valid_moves:
            return 0, None

        best_move = None
        best_eval = float('-inf') if maximizing else float('inf')

        for move in valid_moves:
            eval_score = self._evaluate_move(move, depth, alpha, beta, maximizing)

            if maximizing and eval_score > best_eval:
                best_eval, best_move = eval_score, move
                alpha = max(alpha, eval_score)
            elif not maximizing and eval_score < best_eval:
                best_eval, best_move = eval_score, move
                beta = min(beta, eval_score)

            if beta <= alpha:
                break

        return best_eval, best_move

    def _evaluate_move(self, move, depth, alpha, beta, maximizing):
        """Évalue un coup spécifique."""
        x, y = move
        self.board[x][y] = 1 if maximizing else -1
        self.move_cache.clear()
        eval_score, _ = self.minmax(depth - 1, alpha, beta, not maximizing)
        self.board[x][y] = 0
        return eval_score

    def make_move(self, x, y, player):
        """Effectue un coup sur le plateau."""
        if 0 <= x < self.size and 0 <= y < self.size and self.board[x][y] == 0:
            self.board[x][y] = player
            self.move_cache.clear()
            return True
        return False

    def check_winner(self):
        """Vérifie s'il y a un gagnant."""
        for i in range(self.size):
            for j in range(self.size):
                if self.board[i][j] != 0:
                    player = self.board[i][j]

                    for dx, dy in self.directions:
                        count = 1
                        for step in range(1, 5):
                            ni, nj = i + dx * step, j + dy * step
                            if (ni < 0 or ni >= self.size or
                                nj < 0 or nj >= self.size or
                                self.board[ni][nj] != player):
                                break
                            count += 1

                        if count >= 5:
                            return player
        return 0

    def get_best_move(self):
        """Obtient le meilleur coup possible."""
        eval_score, best_move = self.minmax(self.max_depth, float('-inf'), float('inf'), True)
        return best_move

    def display_board(self):
        """Affiche le plateau de jeu."""
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
    current_player = -1
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