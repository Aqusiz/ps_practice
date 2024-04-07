tile = []
dp = []
dydx = ((1, 0), (-1, 0), (0, 1), (0, -1))
N, M = map(int, input().split())
for _ in range(N):
    line = list(map(int, input().split()))
    tile.append(line)
    dp.append([-1 for _ in range(M)])

def dfs(y, x):
    if y == N-1 and x == M-1:
        return 1
    if dp[y][x] != -1:
        return dp[y][x]
    
    dp[y][x] = 0
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if ny < 0 or nx < 0 or ny >= N or nx >= M or tile[ny][nx] >= tile[y][x]:
            continue
        dp[y][x] += dfs(ny, nx)
    return dp[y][x]

print(dfs(0, 0))