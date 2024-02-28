from collections import deque
dydx = ((1, 0), (0, 1), (-1, 0), (0, -1))
tile = []
H, W = map(int, input().split())
for _ in range(H):
    tile.append(list(input()))

def traverse(i, j):
    """
    run bfs from (i, j) and return the maximum distance
    """
    ret = 0
    q = deque([(i, j, 0)])
    visited = [[False for _ in range(W)] for _ in range(H)]
    
    while q:
        y, x, dist = q.popleft()
        if visited[y][x]:
            continue
        
        visited[y][x] = True
        ret = max(ret, dist)
        for dy, dx in dydx:
            ny, nx = y + dy, x + dx
            if ny < 0 or nx < 0 or ny >= H or nx >= W or visited[ny][nx] or tile[ny][nx] == 'W':
                continue
            q.append((ny, nx, dist + 1))

    return ret

ans = 0
for i in range(H):
    for j in range(W):
        if tile[i][j] == 'W':
            continue
        ans = max(ans, traverse(i, j))

print(ans)