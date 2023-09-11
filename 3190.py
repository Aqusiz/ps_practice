dy = [0, 1, 0, -1]  # right, down, left, up
dx = [1, 0, -1, 0]

N = int(input())
# 0: blank 1: body 2: apple
board = [[0 for _ in range(N)] for _ in range(N)]

K = int(input())
for _ in range(K):
    i, j = map(int, input().split())
    board[i-1][j-1] = 2

L = int(input())
cmd = []
for _ in range(L):
    x, d = input().split()
    cmd.append((int(x), d))

tik = 0
q = [(0, 0, 0)]
board[0][0] = 1
while True:
    tik += 1
    y, x, d = q[-1]
    ny = y + dy[d]
    nx = x + dx[d]
    nd = d
    
    if (ny < 0 or nx < 0 or ny >= N or nx >= N) or board[ny][nx] == 1:
        print(tik)
        break
    elif board[ny][nx] == 0:
        board[q[0][0]][q[0][1]] = 0
        q.pop(0)
    
    if len(cmd) > 0 and cmd[0][0] == tik:
        if cmd[0][1] == "L":
            nd = (nd-1) % 4
        else:
            nd = (nd+1) % 4
        cmd.pop(0)
    
    board[ny][nx] = 1
    q.append((ny, nx, nd))