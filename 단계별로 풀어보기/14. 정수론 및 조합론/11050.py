def fib(n):
    answer = 1
    for i in range(1, n+1):
        answer *= i
    return answer

N, k = map(int, input().split())
print(fib(N)//(fib(k) * fib(N-k)))