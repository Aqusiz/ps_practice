import sys
sys.setrecursionlimit(10000)

N, L, R = map(int, input().split())
A = []
for _ in range(N):
    line = list(map(int, input().split()))
    A.append(line)
dydx = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def find_union(tile, visited, y, x):
    """
    check visited and return a list of unions found by dfs
    """
    ret = [(y, x)]
    n = len(tile)
    visited[y][x] = True
    
    for dy, dx in dydx:
        ny, nx = y + dy, x + dx
        if ny < 0 or ny >= n or nx < 0 or nx >= n or visited[ny][nx]:
            continue
        if abs(tile[ny][nx] - tile[y][x]) < L or abs(tile[ny][nx] - tile[y][x]) > R:
            continue
        ret += find_union(tile, visited, ny, nx)
    
    return ret

cnt = 0
while True:
    visited = [[False for _ in range(N)] for _ in range(N)]
    union_list = []
    for r in range(N):
        for c in range(N):
            if visited[r][c]:
                continue
            union = find_union(A, visited, r, c)
            if len(union) > 1:
                union_list.append(union)
    if not union_list:
        break
    for union in union_list:
        total = 0
        num = len(union)
        for y, x in union:
            total += A[y][x]
        for y, x in union:
            A[y][x] = total // num
    cnt += 1

print(cnt)