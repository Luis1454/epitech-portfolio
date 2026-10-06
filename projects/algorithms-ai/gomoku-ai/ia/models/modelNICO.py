import time
from collections import defaultdict
import random

class TimeManager:
    def __init__(self, max_time=4.5):
        self.max_time = max_time
        self.start_time = 0
        self.move_times = []  # Track time taken for each move
        self.time_per_depth = {}  # Track average time per depth

    def start(self):
        self.start_time = time.time()

    def elapsed(self):
        return time.time() - self.start_time

    def should_continue(self, depth, nodes_searched):
        elapsed = self.elapsed()

        # Emergency stop if we're close to time limit
        if elapsed > self.max_time:
            return False

        # Estimate if we have enough time for next depth
        if depth in self.time_per_depth:
            avg_time_per_depth = self.time_per_depth[depth]
            if elapsed + avg_time_per_depth > self.max_time:
                return False

        return True

    def record_depth_time(self, depth, time_taken):
        if depth not in self.time_per_depth:
            self.time_per_depth[depth] = time_taken
        else:
            # Rolling average
            self.time_per_depth[depth] = (self.time_per_depth[depth] * 0.7 + time_taken * 0.3)

    def record_move_time(self, time_taken):
        self.move_times.append(time_taken)
        if len(self.move_times) > 10:  # Keep last 10 moves
            self.move_times.pop(0)

class GomokuAI:
    def __init__(self, board_size=20):
        self.board_size = board_size
        self.directions = [(1, 0), (0, 1), (1, 1), (1, -1)]
        self.transposition_table = {}
        self.max_time = 4.5  # Maximum thinking time in seconds
        self.start_time = 0
        self.patterns = self._initialize_patterns()
        self.opening_book = self._initialize_opening_book()
        self.time_manager = TimeManager()

    def _initialize_patterns(self):
        """Initialize pattern dictionary with scores."""
        # X = player, O = opponent, _ = empty
        return {
            'XXXX_': 10000,  # Open four
            '_XXXX_': 15000,  # Double-open four
            'XXX_X': 10000,  # Split four
            'XX_XX': 10000,  # Split four
            '_XXX__': 3000,  # Open three
            '__XXX_': 3000,  # Open three
            'XX_X': 1000,    # Split three
            'X_XX': 1000,    # Split three
            '_XX__': 100,    # Open two
            '__XX_': 100,    # Open two
            'X__X': 50,      # Split two
        }

    def _initialize_opening_book(self):
        """Initialize opening book with strong starting moves."""
        # Center and near-center openings
        center = self.board_size // 2
        return [
            # Standard openings around center
            (center, center),
            (center-1, center-1),
            (center-1, center),
            (center, center-1),
            # Star points
            (3, 3),
            (3, self.board_size-4),
            (self.board_size-4, 3),
            (self.board_size-4, self.board_size-4),
        ]

    def _get_pattern_string(self, board, x, y, dx, dy, player, length):
        """Get pattern string in a given direction."""
        pattern = []
        for i in range(-length, length+1):
            curr_x, curr_y = x + dx * i, y + dy * i
            if not (0 <= curr_x < self.board_size and 0 <= curr_y < self.board_size):
                pattern.append('#')  # Board edge
            else:
                cell = board[curr_x][curr_y]
                if cell == 0:
                    pattern.append('_')
                elif cell == player:
                    pattern.append('X')
                else:
                    pattern.append('O')
        return ''.join(pattern)

    def _evaluate_patterns(self, board, x, y, player):
        """Evaluate position based on pattern matching."""
        score = 0
        for dx, dy in self.directions:
            pattern = self._get_pattern_string(board, x, y, dx, dy, player, 4)
            for p, p_score in self.patterns.items():
                if p in pattern:
                    score += p_score
                # Also check for opponent's patterns
                opponent_pattern = pattern.replace('X', 'T').replace('O', 'X').replace('T', 'O')
                if p in opponent_pattern:
                    score += p_score * 0.8  # Defensive moves are slightly less valuable
        return score

    def _iterative_deepening(self, board, player, max_depth=4):
        """Implement iterative deepening search with better time management."""
        best_move = None
        nodes_searched = 0

        for depth in range(1, max_depth + 1):
            depth_start_time = time.time()

            if not self.time_manager.should_continue(depth, nodes_searched):
                break

            move = self._minimax(board, depth, float('-inf'), float('inf'), player, True)
            if move is not None:
                best_move = move[1]

            depth_time = time.time() - depth_start_time
            self.time_manager.record_depth_time(depth, depth_time)

        return best_move

    def _minimax(self, board, depth, alpha, beta, player, is_maximizing):
        """Minimax algorithm with alpha-beta pruning."""
        board_hash = str(board)  # Simple board hashing
        if board_hash in self.transposition_table:
            return self.transposition_table[board_hash]

        if depth == 0 or time.time() - self.start_time > self.max_time:
            return self._evaluate_board(board, player), None

        candidates = self.get_candidate_moves(board)
        if not candidates:
            return 0, None

        best_move = None
        if is_maximizing:
            max_eval = float('-inf')
            for x, y in candidates:
                if board[x][y] == 0:
                    board[x][y] = player
                    eval_score = self._minimax(board, depth-1, alpha, beta, player, False)[0]
                    board[x][y] = 0

                    if eval_score > max_eval:
                        max_eval = eval_score
                        best_move = (x, y)
                    alpha = max(alpha, eval_score)
                    if beta <= alpha:
                        break
            self.transposition_table[board_hash] = (max_eval, best_move)
            return max_eval, best_move
        else:
            min_eval = float('inf')
            for x, y in candidates:
                if board[x][y] == 0:
                    board[x][y] = 3 - player  # Switch player
                    eval_score = self._minimax(board, depth-1, alpha, beta, player, True)[0]
                    board[x][y] = 0

                    if eval_score < min_eval:
                        min_eval = eval_score
                        best_move = (x, y)
                    beta = min(beta, eval_score)
                    if beta <= alpha:
                        break
            self.transposition_table[board_hash] = (min_eval, best_move)
            return min_eval, best_move

    def _evaluate_board(self, board, player):
        """Evaluate entire board state."""
        score = 0
        for i in range(self.board_size):
            for j in range(self.board_size):
                if board[i][j] == player:
                    score += self._evaluate_patterns(board, i, j, player)
                elif board[i][j] == 3 - player:  # Opponent
                    score -= self._evaluate_patterns(board, i, j, 3 - player) * 0.8
        return score

    def _is_early_game(self, board):
        """Check if the game is in opening phase."""
        stone_count = sum(row.count(1) + row.count(2) for row in board)
        return stone_count <= 6

    def get_candidate_moves(self, board):
        """Get list of candidate moves, prioritizing certain patterns."""
        candidates = []
        for i in range(self.board_size):
            for j in range(self.board_size):
                if board[i][j] == 0:
                    if self._has_neighbor(board, i, j, 2):  # Closer neighbors more important
                        candidates.insert(0, (i, j))
                    elif self._has_neighbor(board, i, j, 3):  # Further neighbors less important
                        candidates.append((i, j))
        return candidates if candidates else [(self.board_size // 2, self.board_size // 2)]

    def _has_neighbor(self, board, x, y, distance):
        """Check if position has any neighbors within given distance."""
        for i in range(max(0, x - distance), min(self.board_size, x + distance + 1)):
            for j in range(max(0, y - distance), min(self.board_size, y + distance + 1)):
                if board[i][j] != 0:
                    return True
        return False

    def find_best_move(self, board, player):
        """Find the best move with enhanced time management."""
        self.time_manager.start()
        self.transposition_table.clear()

        # Quick check for winning moves (highest priority)
        winning_move = self._check_winning_move(board, player)
        if winning_move:
            move_time = self.time_manager.elapsed()
            self.time_manager.record_move_time(move_time)
            return winning_move

        # Early game book moves (very fast)
        if self._is_early_game(board):
            for move in self.opening_book:
                if board[move[0]][move[1]] == 0:
                    move_time = self.time_manager.elapsed()
                    self.time_manager.record_move_time(move_time)
                    return move

        # Main search with time management
        best_move = self._iterative_deepening(board, player)
        if best_move:
            move_time = self.time_manager.elapsed()
            self.time_manager.record_move_time(move_time)
            return best_move

        # Fallback to simple evaluation (very fast)
        candidates = self.get_candidate_moves(board)
        best_score = float('-inf')
        best_move = candidates[0]

        for x, y in candidates:
            if board[x][y] == 0:
                score = self._evaluate_patterns(board, x, y, player)
                if score > best_score:
                    best_score = score
                    best_move = (x, y)

        move_time = self.time_manager.elapsed()
        self.time_manager.record_move_time(move_time)
        return best_move

    def _check_winning_move(self, board, player):
        """Check for immediate winning moves."""
        candidates = self.get_candidate_moves(board)
        for x, y in candidates:
            if board[x][y] == 0:
                board[x][y] = player
                if self.is_winning_move(board, x, y, player):
                    board[x][y] = 0
                    return (x, y)
                board[x][y] = 0
        return None

    def is_winning_move(self, board, x, y, player):
        """Check if the last move at (x,y) creates a winning position."""
        for dx, dy in self.directions:
            count = 1

            # Check in both directions
            for factor in [-1, 1]:
                curr_x, curr_y = x, y
                for _ in range(4):
                    curr_x += dx * factor
                    curr_y += dy * factor
                    if not (0 <= curr_x < self.board_size and 0 <= curr_y < self.board_size):
                        break
                    if board[curr_x][curr_y] == player:
                        count += 1
                    else:
                        break

            if count >= 5:
                return True

        return False