dp = dict()
dp[0] = 1
dp[1] = 1

N, k = map(int, input().split())
for i in range(2, N+1):
    dp[i] = dp[i-1] * i
print((dp[N] // (dp[k] * dp[N-k])) % 10007)