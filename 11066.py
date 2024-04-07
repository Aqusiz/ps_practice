import sys
input = sys.stdin.readline

INF = 987654321
T = int(input())
for _ in range(T):
    # input
    K = int(input())
    files = [0] + list(map(int, input().split()))
    dp = [[0 for _ in range(K + 1)] for _ in range(K + 1)]
    # acc sum
    acc = [0 for _ in range(K + 1)]
    for i in range(1, K+1):
        acc[i] = acc[i - 1] + files[i]
    # dp[j][j + i]: i부터 j+i까지 파일을 합치는 최소 비용
    for i in range(1, K + 1):                   # i: 간격
        for j in range(1, K + 1 - i):           # j: 시작 지점
            dp[j][j + i] = INF
            for k in range(j, j + i):           # k: 중간 지점 (2개의 파일을 합치기 위해)
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k+1][j + i] + (acc[j + i] - acc[j - 1]))
    
    print(dp[1][K])