import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

N = int(input())
M = int(input())

adj = [[] for _ in range(N+1)]

for _ in range(M):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
start, dest = map(int, input().split())

# use dijkstra
def find_cost(start, dest, adj):
    pq = []
    dist = [INF for _ in range(N+1)]
    
    dist[start] = 0
    heapq.heappush(pq, (0, start))
    while pq:
        curr_w, curr_v = heapq.heappop(pq)
        if dist[curr_v] < curr_w:
            continue
        for nv, nw in adj[curr_v]:
            if dist[nv] > curr_w + nw:
                dist[nv] = curr_w + nw
                heapq.heappush(pq, (dist[nv], nv))
    return dist[dest]

print(find_cost(start, dest, adj))