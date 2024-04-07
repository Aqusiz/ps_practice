import sys
input = sys.stdin.readline

N, C = map(int, input().rstrip().split())
houses = [0 for _ in range(N)]
for i in range(N):
    houses[i] = int(input().rstrip())
houses.sort()

def set_router(min_dist):
    cnt = 1
    last_location = 0
    for i in range(1, N):
        if houses[i] - houses[last_location] >= min_dist:
            cnt += 1
            last_location = i
    return cnt

st = 1
ed = houses[-1] - houses[0] + 1
while st < ed:
    mid = (st + ed) // 2
    router_num = set_router(mid)

    if router_num < C:
        ed = mid
    else:
        st = mid + 1

print(st - 1)