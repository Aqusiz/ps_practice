dxdy = ((1, 0), (0, -1), (-1, 0), (0, 1))
dc_list = []
ans = 0
N = int(input())
for _ in range(N):
    x, y, d, g = map(int, input().split())
    dc_list.append((x, y, d, g))

def make_dragon_curve(x, y, d, g):
    if g == 0:
        dx, dy = dxdy[d]
        return [(x, y), (x + dx, y + dy)]
    
    coord_list = make_dragon_curve(x, y, d, g-1)
    
    d_list = []
    for i in range(len(coord_list) - 1):
        x1, y1 = coord_list[i]
        x2, y2 = coord_list[i + 1]
        dx, dy = x2 - x1, y2 - y1
        d_list.append((dxdy.index((dx, dy)) + 1) % 4)
    d_list.reverse()
    x, y = coord_list[-1]
    for direction in d_list:
        dx, dy = dxdy[direction]
        x, y = x + dx, y + dy
        coord_list.append((x, y))
    
    return coord_list

coord_list = []
for dc in dc_list:
    coord_list += make_dragon_curve(*dc)

for i in range(100):
    for j in range(100):
        if (i, j) in coord_list and (i + 1, j) in coord_list and (i, j + 1) in coord_list and (i + 1, j + 1) in coord_list:
            ans += 1
print(ans)