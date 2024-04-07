"""
문제 해석: 가중치가 있는 트리 형태의 자료구조에서, 두 정점 v1, v2 사이의 usado = v1에서부터 v2까지 가는 길에 존재하는 가중치의 최솟값
풀이: 모든 정점 쌍에 대해 usado 기록. 이때 dfs 방식을 이용하는데, 원점 v1, 직전 정점 v2, 새 정점 v3에 대해, min(usado(v1, v2), weight(v2, v3))를 기록
참고: python3 -> TLE / pypy -> AC
"""
from collections import deque
INF = 1000000001

N, Q = map(int, input().split())
adj = [[] for _ in range(N+1)]
usado = [[INF for j in range(N+1)] for i in range(N+1)]

for _ in range(N-1):
    p, q, r = map(int, input().split())
    adj[p].append((q, r))
    adj[q].append((p, r))

for v1 in range(1, N+1):
    visited = [False for _ in range(N+1)]
    visited[v1] = True
    
    stack = deque()
    for v2, r in adj[v1]:
        stack.append((v2, r, v1))
    
    while stack:
        v2, r, prev = stack.popleft()
        visited[v2] = True
        usado[v1][v2] = min(usado[v1][v2], usado[v1][prev], r)
        for v3, new_r in adj[v2]:
            if not visited[v3]:
                stack.append((v3, new_r, v2))

for _ in range(Q):
    k, v = map(int, input().split())
    ans = 0
    for v in usado[v]:
        if k <= v < INF:
            ans += 1
    print(ans)