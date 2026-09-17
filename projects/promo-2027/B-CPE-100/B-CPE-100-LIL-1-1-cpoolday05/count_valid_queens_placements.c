/*
** EPITECH PROJECT, 2022
** count_valid_queens_placements.c
** File description:
** N-queens problem
*/

int my_compute_power_rec(int nb, int p);

long long my_normalize(long long nb);

int is_threatened(int i, int j, int n, int *board)
{
    int a = 0;
    int b = 0;

    for (int k = 0; k < n * n; k++) {
        a = k / n;
        b = k - (int) (k / n) * n;
        if (board[a * n + b] && ((i == a || j == b)
        || my_normalize(my_normalize(a) - my_normalize(i))
        == my_normalize(my_normalize(b) - my_normalize(j)))
        && (i != a || j != b))
            return 1;
    }
    return 0;
}

int *configure_board(int n, int *board, int id)
{
    int pos;

    for (int i = 0; i < n * n; i++)
        board[i] = 0;
    for (int i = 0; i < n; i++) {
        pos = i ? (id / my_compute_power_rec(n, i)) : id;
        pos = pos - (int) (pos / n) * n;
        board[i * n + pos] = 1;
    }
    return board;
}

int is_checked(int n, int *board)
{
    for (int i = 0; i < n; i++)
        if (!board[i * n + n - 1])
            return 0;
    return 1;
}

int get_placement(int *board, unsigned long long id, long long nb, int n)
{
    int state = 1;

    if (is_checked(n, board))
        return nb;
    board = configure_board(n, board, id);
    for (int i = 0; i < n * n; i++)
        if (board[i])
            state *= (!is_threatened(i / n, i - (int) (i / n) * n, n, board));
    nb += state;
    get_placement(board, id + 1, nb, n);
}

int count_valid_queens_placements(int n)
{
    int board[n * n];

    if (0 > n || n >= 7)
        return 0;
    for (int i = 0; i < n * n; i++)
        board[i] = 0;
    return get_placement(board, 0, 0, n);
}
