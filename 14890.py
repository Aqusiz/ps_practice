N, L = map(int, input().split())
tile = []
for _ in range(N):
    line = list(map(int, input().split()))
    tile.append(line)
    
def is_passable(line, l):
    n = len(line)
    set_slope = [False for _ in range(n)]
    idx = 1
    while idx < n:
        # 2칸 이상 차이 나는 경우
        if abs(line[idx - 1] - line[idx]) > 1:
            return False
        # 1칸 낮아지는 경우: 앞 L칸에 경사로 설치가 가능한가?
        if line[idx - 1] - line[idx] == 1:
            for j in range(l):
                # 길을 벗어났거나, 같은 높이가 아니거나, 이미 경사로가 설치되어 있는 경우
                if idx + j >= n or line[idx] != line[idx + j] or set_slope[idx + j]:
                    return False
                set_slope[idx + j] = True
            idx += j    # 이미 체크한 부분 건너뛰기
        # 1칸 높아지는 경우: 뒤 L칸에 경사로 설치가 가능한가?
        elif line[idx] - line[idx - 1] == 1:
            for j in range(l):
                # 길을 벗어났거나, 같은 높이가 아니거나, 이미 경사로가 설치되어 있는 경우
                if idx - 1 - j < 0 or line[idx - 1] != line[idx - 1 - j] or set_slope[idx - 1 - j]:
                    return False
                set_slope[idx - 1 - j] = True
        idx += 1

    return True

ans = 0
for i in range(N):
    if is_passable(tile[i], L):
        ans += 1
    col = [tile[j][i] for j in range(N)]
    if is_passable(col, L):
        ans += 1
print(ans)