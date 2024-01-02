N = int(input())
tile = []
for _ in range(N):
    line = list(map(int, input().split()))
    tile.append(line)

cnt = 0
# y, x, state(0: horizontal, 1: vertical, 2: diagonal)
stack = [(0, 1, 0)]
while stack:
    y, x, state = stack.pop()
    if y == x == N-1:
        cnt += 1
        continue
    if (state == 0 or state == 2) and x+1 < N and tile[y][x+1] == 0:
        stack.append((y, x+1, 0))
    if (state == 1 or state == 2) and y+1 < N and tile[y+1][x] == 0:
        stack.append((y+1, x, 1))
    if y+1 < N and x+1 < N and tile[y][x+1] + tile[y+1][x+1] + tile[y+1][x] == 0:
        stack.append((y+1, x+1, 2))
        
print(cnt)