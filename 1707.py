import sys
input = sys.stdin.readline

def bfs(start, adj, visited):
    q = [start]
    visited[start] = 1
    while q:
        u = q.pop(0)
        for v in adj[u]:
            if visited[v] == 0:
                visited[v] = -visited[u]
                q.append(v)

def is_bipartite(adj, visited):
    V = len(adj) - 1
    for u in range(1, V + 1):
        for v in adj[u]:
            if visited[u] == visited[v]:
                return False
    return True

K = int(input())
for _ in range(K):
    V, E = map(int, input().split())
    adj = [[] for _ in range(V+1)]
    visited = [0 for _ in range(V+1)]   # 0: not visited 1, -1: visited
    for _ in range(E):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    
    for i in range(1, V+1):
        if visited[i] == 0:
            bfs(i, adj, visited)
    
    print("YES" if is_bipartite(adj, visited) else "NO")