import heapq
shark = [(-1, -1), 2, 0]    # shark[0]: position, shark[1]: size, shark[2]: # of fish ate
tile = []
dydx = ((1, 0), (-1, 0), (0, 1), (0, -1))
ans = 0
# input
N = int(input())
for i in range(N):
    line = list(map(int, input().split()))
    tile.append(line)
    if 9 in line:
        shark[0] = (i, line.index(9))

class Fish(object):
    """
    Fish object for custom priority queue comparision
    """
    def __init__(self, dist, y, x):
        self.dist = dist
        self.y = y
        self.x = x
    def __lt__(self, other):
        if self.dist < other.dist:
            return True
        elif self.dist == other.dist and self.y < other.y:
            return True
        elif self.dist == other.dist and self.y == other.y and self.x < other.x:
            return True
        return False

while True:
    fish_pq = []
    shark_q = []
    visited = [[False for _ in range(N)] for _ in range(N)]
    # bfs for shark's position
    y, x = shark[0]
    shark_q.append((y, x, 0))
    while shark_q:
        j, i, dist = shark_q.pop(0)
        if visited[j][i]:
            continue
        visited[j][i] = True
        # heappush if the tile is fish and the size of fish is smaller than shark's
        if tile[j][i] != 9 and 0 < tile[j][i] < shark[1]:
            heapq.heappush(fish_pq, Fish(dist, j, i))
        for dy, dx in dydx:
            ny, nx = j + dy, i + dx
            if ny < 0 or nx < 0 or ny >= N or nx >= N or visited[ny][nx]:
                continue
            if tile[ny][nx] > shark[1]:
                continue
            shark_q.append((ny, nx, dist + 1))
    # no edible fish: End
    if not fish_pq:
        print(ans)
        break
    fish = heapq.heappop(fish_pq)
    dist, ny, nx = fish.dist, fish.y, fish.x
    # time elapsed
    ans += dist
    # move shark's position
    shark[0] = (ny, nx)
    tile[y][x] = 0
    tile[ny][nx] = 9
    # shark ate fish
    shark[2] += 1
    # shark size-up
    if shark[2] == shark[1]:
        shark[1] += 1
        shark[2] = 0