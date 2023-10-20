import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

V, E = map(int, input().split())
K = int(input())

adj = [[] for _ in range(V+1)]
dist = [INF for _ in range(V+1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))

def dijkstra(start, dist):
    pq = []
    
    dist[start] = 0
    heapq.heappush(pq, (0, start))
    while pq:
        curr_w, curr_v = heapq.heappop(pq)
        for nv, nw in adj[curr_v]:
            if dist[nv] > curr_w + nw:
                dist[nv] = curr_w + nw
                heapq.heappush(pq, (dist[nv], nv))
    
dijkstra(K, dist)
for i in range(1, V+1):
    print(dist[i] if dist [i] != INF else "INF")