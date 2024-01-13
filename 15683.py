import sys
sys.setrecursionlimit(10000)
tile = []
cctv_list = [(0, 0, 0)]
dydx = ((-1, 0), (0, 1), (1, 0), (0, -1))   # 0: up, 1: right, 2: down, 3: left
cctv_direction = ((), 
                  ((0,), (1,), (2,), (3,)),
                  ((0, 2), (1, 3)),
                  ((0, 1), (1, 2), (2, 3), (3, 0)),
                  ((0, 1, 2), (1, 2, 3), (2, 3, 0), (3, 0, 1)),
                  ((0, 1, 2, 3),))
# input
N, M = map(int, input().split())
for i in range(N):
    line = list(map(int, input().split()))
    tile.append(line)
    for j, value in enumerate(line):
        if value != 0 and value != 6:
            cctv_list.append((i, j, value))

def vision_one_direction(cctv_idx, d, check):
    """
    Check or uncheck vision of one direction d from the cctv
    """
    cctv_y, cctv_x, _ = cctv_list[cctv_idx]
    dy, dx = dydx[d]
    ny, nx = cctv_y + dy, cctv_x + dx
    while True:
        if ny < 0 or nx < 0 or ny >= N or nx >= M or tile[ny][nx] == 6:
            return
        # if check is True, then check cctv's vision
        if check and tile[ny][nx] == 0:
            tile[ny][nx] = -cctv_idx
        # if check is False, then uncheck cctv's vision
        elif not check and tile[ny][nx] == -cctv_idx:
            tile[ny][nx] = 0
        ny, nx = ny + dy, nx + dx

def vision(cctv_idx, directions, check):
    """
    Check or uncheck vision of all directions from the cctv
    """
    for d in directions:
        vision_one_direction(cctv_idx, d, check)

def dfs(cctv_idx):
    if cctv_idx == len(cctv_list):
        ret = 0
        for i in range(N):
            for j in range(M):
                if tile[i][j] == 0:
                    ret += 1
        return ret

    ret = 100
    _, _, cctv_num = cctv_list[cctv_idx]
    for directions in cctv_direction[cctv_num]:
        vision(cctv_idx, directions, True)
        ret = min(dfs(cctv_idx + 1), ret)
        vision(cctv_idx, directions, False)
    return ret

print(dfs(1))