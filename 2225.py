# 0부터 N까지의 정수 중 K개를 더해 N이 되는 경우의 수
mod = 1000000000
N, K = map(int, input().split())

dp = [[0 for _ in range(K+1)] for _ in range(N+1)]
for j in range(1, K+1):
    dp[0][j] = 1

for i in range(1, N+1):
    for j in range(1, K+1):
        dp[i][j] = (dp[i-1][j] % mod + dp[i][j-1] % mod) % mod

print(dp[N][K])