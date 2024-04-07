dydx = ((1, 0), (-1, 0), (0, 1), (0, -1))
tile = []
N = int(input())
for _ in range(N):
    line = list(map(int, input().split()))
    tile.append(line)

def find_island():
    island_tile = [[0 for _ in range(N)] for _ in range(N)]
    visited = [[False for _ in range(N)] for _ in range(N)]
    island_num = 1

    for i in range(N):
        for j in range(N):
            if tile[i][j] == 0 or visited[i][j]:
                continue
            q = [(i, j)]
            while q:
                y, x = q.pop(0)
                if visited[y][x]:   # 없으면 시간 초과
                    continue
                visited[y][x] = True
                island_tile[y][x] = island_num
                for dy, dx in dydx:
                    ny, nx = y + dy, x + dx
                    if ny < 0 or nx < 0 or ny >= N or nx >= N or visited[ny][nx] or tile[ny][nx] == 0:
                        continue
                    q.append((ny, nx))
            island_num += 1

    return island_tile

def is_outline(y, x):
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if ny < 0 or nx < 0 or ny >= N or nx >= N:
            continue
        if tile[ny][nx] == 0:
            return True
    return False

def set_bridge(island_tile):
    ret = 987654321
    visited = [[0 for _ in range(N)] for _ in range(N)]
    visit = 0
    for i in range(N):
        for j in range(N):
            if island_tile[i][j] == 0 or not is_outline(i, j):
                continue
            q = [(i, j, 0)]
            visit += 1
            while q:
                y, x, dist = q.pop(0)
                if visited[y][x] == visit:  # 없으면 시간 초과
                    continue
                visited[y][x] = visit
                for dy, dx in dydx:
                    ny, nx = y + dy, x + dx
                    if (ny < 0 or nx < 0 or ny >= N or nx >= N
                        or island_tile[ny][nx] == island_tile[i][j]
                        or visited[ny][nx] == visit):
                        continue
                    if island_tile[ny][nx] == 0:
                        q.append((ny, nx, dist + 1))
                    else:
                        ret = min(ret, dist)
                        q = []
                        break
    return ret

island_tile = find_island()
print(set_bridge(island_tile))