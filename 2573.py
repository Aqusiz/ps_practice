import sys
sys.setrecursionlimit(10000)
dydx = ((0, 1), (0, -1), (1, 0), (-1, 0))

def _count_icebergs(tile, visited, y, x):
    """
    Check all connected tiles as visited by dfs
    """
    n, m = len(tile), len(tile[0])
    visited[y][x] = True
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if ny < 0 or nx < 0 or ny >= n or nx >= m:
            continue
        if tile[ny][nx] == 0 or visited[ny][nx]:
            continue
        _count_icebergs(tile, visited, ny, nx)

def count_icebergs(tile):
    """
    Return the number of icebergs
    """
    n, m = len(tile), len(tile[0])
    visited = [[False for _ in range(m)] for _ in range(n)]
    ret = 0
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if tile[i][j] == 0 or visited[i][j]:
                continue
            _count_icebergs(tile, visited, i, j)
            ret += 1
    return ret

def melt(tile, y, x):
    """
    Return the number of zeros arount the coord(y, x)
    """
    cnt = 0
    for dy, dx in dydx:
        if tile[y + dy][x + dx] == 0:
            cnt += 1
    return cnt

N, M = map(int, input().split())
tile = []
year = 0
for _ in range(N):
    line = list(map(int, input().split()))
    tile.append(line)

while True:
    year += 1
    # 모든 빙산은 '동시에' 녹는다
    # 각 칸을 동시에 녹이지 않으면, 이번 차례에 0이 된 칸이 옆 칸을 녹이면서 오류 발생
    melt_tile = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(1, N - 1):
        for j in range(1, M - 1):
            if tile[i][j] == 0:
                continue
            melt_tile[i][j] = melt(tile, i, j)
    for i in range(1, N - 1):
        for j in range(1, M - 1):
            tile[i][j] = max(0, tile[i][j] - melt_tile[i][j])
    
    if count_icebergs(tile) >= 2:
        print(year)
        break
    elif sum(sum(tile, [])) == 0:
        print(0)
        break