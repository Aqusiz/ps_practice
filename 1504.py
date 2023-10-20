import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

N, E = map(int, input().split())
adj = [[] for _ in range(N+1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))
v1, v2 = map(int, input().split())

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
    return dist

dist1 = dijkstra(1, adj)
distN = dijkstra(N, adj)
distv1 = dijkstra(v1, adj)

path1 = dist1[v1] + distv1[v2] + distN[v2]
path2 = dist1[v2] + distv1[v2] + distN[v1]

print(min(path1, path2) if path1 < INF and path2 < INF else -1)