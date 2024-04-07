import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

cmd = list(map(int, input().split()))
cost = {0: 1, 1: 3, 2: 4, 3: 3}   # 같은 지점: 1, 인접한 지점: 3, 반대 지점: 4
dp = [[[-1 for _ in range(5)] for _ in range(5)] for _ in range(len(cmd) + 1)]

def step(idx, left, right):
    if cmd[idx] == 0:
        return 0
    if dp[idx][left][right] != -1:
        return dp[idx][left][right]
    
    next_step = cmd[idx]
    if next_step == left or next_step == right:
        dp[idx][left][right] = 1 + step(idx + 1, left, right)
    else:
        left_cost = cost[abs(left - next_step)] if left != 0 else 2
        right_cost = cost[abs(right - next_step)] if right != 0 else 2
        dp[idx][left][right] = min(left_cost + step(idx + 1, next_step, right), right_cost + step(idx + 1, left, next_step))
    
    return dp[idx][left][right]

print(step(0, 0, 0))