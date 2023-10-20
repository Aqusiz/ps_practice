import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

N, M, X = map(int, input().split())
adj = [[] for _ in range(N+1)]
adj_r = [[] for _ in range(N+1)]

for _ in range(M):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj_r[v].append((u, w))

# return: list of dist
def dijkstra(start, adj):
    pq = []
    dist = [INF if i != start else 0 for i in range(N+1)]
    heapq.heappush(pq, (0, start))
    while pq:
        curr_w, curr_v = heapq.heappop(pq)
        for nv, nw in adj[curr_v]:
            if dist[nv] > curr_w + nw:
                dist[nv] = curr_w + nw
                heapq.heappush(pq, (dist[nv], nv))
    
    return dist[1:]

dist1 = dijkstra(X, adj)
dist2 = dijkstra(X, adj_r)

print(max([t1 + t2 for t1, t2 in zip(dist1, dist2)]))