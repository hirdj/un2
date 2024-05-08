def is_safe(board, row, col, N):
    # Check row on left side
    for i in range(col):
        if board[row][i]:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j]:
            return False

    return True

def solve_n_queens_util(board, col, N):
    if col >= N:
        return True

    for i in range(N):
        if is_safe(board, i, col, N):
            board[i][col] = 1
            if solve_n_queens_util(board, col + 1, N):
                return True
            board[i][col] = 0  # Backtrack

    return False

def solve_n_queens(N):
    board = [[0] * N for _ in range(N)]

    if not solve_n_queens_util(board, 0, N):
        # print("Solution does not exist")
        return

    # Print the solution
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print()

if __name__ == "__main__":
    N = 4  # Board size
    solve_n_queens(N)
