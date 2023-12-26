# 2023 kakao internship
# AC

def solution(n, tops):
    answer = 0
    div = 10007
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    dp[1] = 3 if tops[0] == 0 else 4
    
    for i in range(2, n+1):
        if tops[i-1] == 0:
            mul1 = 2
            mul2 = 3
        else:
            mul1 = 3
            mul2 = 4
        dp[i] = ((dp[i-2] * mul1)%div + ((dp[i-1] - dp[i-2]) * mul2)%div)%div
        
    answer = dp[n]
    return answer

print(solution(4, [1, 1, 0, 1]))
print(solution(2, [0, 1]))
print(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]))