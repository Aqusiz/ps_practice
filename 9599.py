def solve(n, k, s):
    if k == 0:
        return 1 if s == 0 else 0
    
    answer = 0
    for i in range(n, 0, -1):
        answer += solve(i - 1, k - 1, s - i)
    
    return answer

while True:
    n, k, s = map(int, input().split())
    if n == 0 and k == 0 and s == 0:
        break
    print(solve(n, k, s))