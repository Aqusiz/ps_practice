# Input
N, M, H = map(int, input().split())
ladder = [[False for _ in range(N + 1)] for _ in range(H + 1)]
ans = 4
for _ in range(M):
    a, b = map(int, input().split())
    ladder[a][b] = True

def check_ladder():
    """
    If all i-th vertical lines end at i, return True.
    Else return False
    """
    ret = True
    for i in range(1, N + 1):
        if not ret:
            break
        curr = i
        for j in range(1, H + 1):
            if ladder[j][curr]:
                curr += 1
            elif ladder[j][curr - 1]:
                curr -= 1
        ret = ret and (curr == i)
    
    return ret

def solve(y, x, ladder_num):
    """
    Return the minimun number of ladders need. If it is impossible or the number is larger than 3, return 4.
    Solved by backtracking.
    """
    if ladder_num > 3:
        return 4
    if check_ladder():
        return ladder_num
    
    ret = 4
    # y line
    for j in range(x + 2, N):
        if ladder[y][j] or ladder[y][j - 1] or ladder[y][j + 1]:
            continue
        ladder[y][j] = True
        ret = min(ret, solve(y, j , ladder_num + 1))
        ladder[y][j] = False
    # y+1 ~ H lines
    for i in range(y + 1, H + 1):
        for j in range(1, N):
            if ladder[i][j] or ladder[i][j - 1] or ladder[i][j + 1]:
                continue
            ladder[i][j] = True
            ret = min(ret, solve(i, j, ladder_num + 1))
            ladder[i][j] = False
    
    return ret
# Solve
if check_ladder():
    print(0)
else:
    for i in range(1, H + 1):
        for j in range(1, N):
            if ladder[i][j] or ladder[i][j - 1] or ladder[i][j + 1]:
                continue
            ladder[i][j] = True
            ans = min(ans, solve(i, j, 1))
            ladder[i][j] = False

    print(ans if ans < 4 else -1)