import sys
input = sys.stdin.readline
# input
# commands = 1: East, 2: West, 3: North, 4: South
N, M, y, x, K = map(int, input().split())
tile = []
for _ in range(N):
    line = list(map(int, input().split()))
    tile.append(line)
cmds = list(map(int, input().split()))
dice = {'t': 0, 'b': 0, 'e': 0, 'w': 0, 'n': 0, 's': 0}
dydx = [(), (0, 1), (0, -1), (-1, 0), (1, 0)]

for cmd in cmds:
    dy, dx = dydx[cmd]
    if y + dy < 0 or y + dy >= N or x + dx < 0 or x + dx >= M:
        continue
    
    if cmd == 1:
        dice['t'], dice['e'], dice['b'], dice['w'] = dice['w'], dice['t'], dice['e'], dice['b']
    elif cmd == 2:
        dice['t'], dice['e'], dice['b'], dice['w'] = dice['e'], dice['b'], dice['w'], dice['t']
    elif cmd == 3:
        dice['t'], dice['n'], dice['b'], dice['s'] = dice['s'], dice['t'], dice['n'], dice['b']
    else:
        dice['t'], dice['n'], dice['b'], dice['s'] = dice['n'], dice['b'], dice['s'], dice['t']
    
    y, x = y + dy, x + dx
    if tile[y][x] == 0:
        tile[y][x] = dice['b']
    else:
        dice['b'] = tile[y][x]
        tile[y][x] = 0
    
    print(dice['t'])