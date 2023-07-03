board = []
row = [[False for _ in range(10)] for _ in range(9)]
col = [[False for _ in range(10)] for _ in range(9)]
square = [[False for _ in range(10)] for _ in range(9)]
done = False

def assign(r, c, v):
    global board, row, col, square
    board[r][c] = v
    row[r][v] = True
    col[c][v] = True
    square[(r // 3)*3 + (c // 3)][v] = True

def restore(r, c, v):
    global board, row, col, square
    board[r][c] = 0
    row[r][v] = False
    col[c][v] = False
    square[(r // 3)*3 + (c // 3)][v] = False

def dfs(r, c):
    global board, row, col, square, done
    if done:
        return
    if r == 9:
        done = True
        for line in board:
            for digit in line:
                print(digit, end="")
            print()
        return

    n_r = r
    n_c = c + 1
    if n_c == 9:
        n_r += 1
        n_c = 0

    if board[r][c] == 0:
        for i in range(1, 10):
            if row[r][i] or col[c][i] or square[(r // 3)*3 + (c // 3)][i]:
                continue
            assign(r, c, i)
            dfs(n_r, n_c)
            restore(r, c, i)
    else:
        dfs(n_r, n_c)

# input
for i in range(9):
    line = input()
    l = []
    for digit in line:
        l.append(int(digit))
    board.append(l)
# init
for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            continue
        row[i][board[i][j]] = True
        col[j][board[i][j]] = True
        square[(i // 3)*3 + (j // 3)][board[i][j]] = True

dfs(0, 0)