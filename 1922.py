# prim algorithm
import sys
import heapq
input = sys.stdin.readline

N = int(input())
M = int(input())
adj = [[] for _ in range(N+1)]
pq = []
visited = [False for _ in range(N+1)]
ans = 0
for _ in range(M):
    a, b, c = map(int, input().split())
    adj[a].append((c, b))
    adj[b].append((c, a))

visited[1] = True
for cv in adj[1]:
    heapq.heappush(pq, cv)
while pq:
    cost, u = heapq.heappop(pq)
    if visited[u]:
        continue
    visited[u] = True
    ans += cost
    for cv in adj[u]:
        heapq.heappush(pq, cv)

print(ans)