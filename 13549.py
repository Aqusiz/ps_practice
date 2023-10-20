q = []
INF = 987654321
MAX = 100000

N, K = map(int, input().split())
time = [INF if i != N else 0 for i in range(100001)]

q.append(N)
while q:
    curr = q.pop(0)
    cost = time[curr]
    
    if curr == K:
        print(cost)
        break
    
    for n, c in ((curr * 2, cost), (curr + 1, cost + 1), (curr - 1, cost + 1)):
        if n < 0 or n > MAX or time[n] <= c:
            continue
        time[n] = c
        q.append(n)