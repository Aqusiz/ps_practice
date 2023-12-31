# N: 0, S: 1
# 시계: 1, 반시계: -1
# 맞닿는 부분 idx: 2, 6
cogwheel = [[]]

def rotate(wheel_num, direction):
    if direction == 1:
        cogwheel[wheel_num] = [cogwheel[wheel_num][-1]] + cogwheel[wheel_num][:-1]
    else:
        cogwheel[wheel_num] = cogwheel[wheel_num][1:] + [cogwheel[wheel_num][0]]

for _ in range(4):
    cogs = list(map(int, list(input())))
    cogwheel.append(cogs)

k = int(input())
for _ in range(k):
    wheel_num, d = map(int, input().split())
    cog_left, cog_right = cogwheel[wheel_num][6], cogwheel[wheel_num][2]
    left_d, right_d = d, d
    rotate(wheel_num, d)
    # to the left
    for i in range(wheel_num - 1, 0, -1):
        if cogwheel[i][2] == cog_left:
            break
        cog_left, left_d = cogwheel[i][6], -left_d
        rotate(i, left_d)
    # to the right
    for i in range(wheel_num + 1, 5):
        if cogwheel[i][6] == cog_right:
            break
        cog_right, right_d = cogwheel[i][2], -right_d
        rotate(i, right_d)

ans = 0
for i in range(1, 5):
    ans += cogwheel[i][0] * (2 ** (i-1))
print(ans)