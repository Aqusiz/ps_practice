coins = []
n, k = map(int, input().split())
dp = [10001 for _ in range(k + 1)]
dp[0] = 0

for _ in range(n):
    coins.append(int(input()))

for i in range(n):
    for j in range(coins[i], k + 1):
        dp[j] = min(dp[j], dp[j - coins[i]] + 1)

print(dp[k] if dp[k] != 10001 else -1)