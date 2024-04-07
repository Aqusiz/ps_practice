from collections import deque
dydx = ((0, 1), (0, -1), (1, 0), (-1, 0))
horse_dydx = ((2, 1), (1, 2), (-2, 1), (-1, 2), (2, -1), (1, -2), (-2, -1), (-1, -2))

K = int(input())
W, H = map(int, input().split())
tile = []
visited = [[[False for _ in range(W)] for _ in range(H)] for _ in range(K+1)]
for _ in range(H):
    line = list(map(int, input().split()))
    tile.append(line)

def is_in_tile(y, x):
    return y >= 0 and x >= 0 and y < H and x < W

ans = -1
q = deque([(0, 0, 0, K)])   # (y, x, dist, k)
while q:
    y, x, dist, k = q.popleft()
    if visited[k][y][x]:
        continue
    if y == H - 1 and x == W - 1:
        ans = dist
        break

    visited[k][y][x] = True
    # move to a near tile
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if not is_in_tile(ny, nx) or visited[k][ny][nx] or tile[ny][nx] == 1:
            continue
        q.append((ny, nx, dist + 1, k))
    # horse's move
    if k > 0:
        for dy, dx in horse_dydx:
            ny, nx = y + dy, x + dx
            if not is_in_tile(ny, nx) or visited[k - 1][ny][nx] or tile[ny][nx] == 1:
                continue
            q.append((ny, nx, dist + 1, k - 1))

print(ans)