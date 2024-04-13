UP, DOWN, RIGHT, LEFT = 1, 2, 3, 4

R, C, M = map(int, input().split())
tile = [[(-1, -1, -1) for _ in range(C+1)] for _ in range(R+1)]
position = 0
answer = 0

for _ in range(M):
    r, c, s, d, z = map(int, input().split())
    tile[r][c] = (s, d, z)


def fishing():
    global answer, tile, position
    for y in range(1, R+1):
        if tile[y][position] == (-1, -1, -1):
            continue
        _, _, size = tile[y][position]
        answer += size
        tile[y][position] = (-1, -1, -1)
        return


def get_next_loc(y, x, speed, direction):
    if direction == UP:
        if speed < y-1:
            return y-speed, x, UP
        speed -= y-1
        cycle = R-1
        a, b = speed // cycle, speed % cycle
        if a % 2 == 0:
            return b+1, x, DOWN
        else:
            return R-b, x, UP
    elif direction == DOWN:
        if speed < R - y:
            return y + speed, x, DOWN
        speed -= R-y
        cycle = R-1
        a, b = speed // cycle, speed % cycle
        if a % 2 == 0:
            return R-b, x, UP
        else:
            return b+1, x, DOWN
    elif direction == LEFT:
        if speed < x - 1:
            return y, x - speed, LEFT
        speed -= x-1
        cycle = C-1
        a, b = speed // cycle, speed % cycle
        if a % 2 == 0:
            return y, b+1, RIGHT
        else:
            return y, C-b, LEFT
    else:
        if speed < C - x:
            return y, x + speed, RIGHT
        speed -= C-x
        cycle = C-1
        a, b = speed // cycle, speed % cycle
        if a % 2 == 0:
            return y, C-b, LEFT
        else:
            return y, b+1, RIGHT


def move():
    global tile
    new_tile = [[(-1, -1, -1) for _ in range(C+1)] for _ in range(R+1)]
    for y in range(1, R+1):
        for x in range(1, C+1):
            if tile[y][x] == (-1, -1, -1):
                continue
            speed, direction, size = tile[y][x]
            ny, nx, nd = get_next_loc(y, x, speed, direction)

            if new_tile[ny][nx] == (-1, -1, -1) or new_tile[ny][nx][2] < size:
                new_tile[ny][nx] = (speed, nd, size)

    return new_tile


while position < C:
    position += 1
    fishing()
    tile = move()

print(answer)
