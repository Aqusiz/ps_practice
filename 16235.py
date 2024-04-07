import sys
from collections import deque

input = sys.stdin.readline
drdc = ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1))
N, M, K = map(int, input().split())
A = []
energy = [[5 for _ in range(N)] for _ in range(N)]
trees = [[deque() for _ in range(N)] for _ in range(N)]

for _ in range(N):
    line = list(map(int, input().split()))
    A.append(line)
for _ in range(M):
    x, y, z = map(int, input().split())
    trees[x-1][y-1].append(z)

for _ in range(K):
    # spring
    dead_trees = []
    reprod_trees = deque()
    for r in range(N):
        for c in range(N):
            for _ in range(len(trees[r][c])):
                tree = trees[r][c].popleft()
                if tree > energy[r][c]:
                    dead_trees.append((r, c, tree//2))
                    continue
                energy[r][c] -= tree
                trees[r][c].append(tree + 1)
                if (tree + 1) % 5 == 0:
                    reprod_trees.append((r, c))
            # winter
            energy[r][c] += A[r][c]
    # summer
    for dead_tree in dead_trees:
        r, c, z = dead_tree
        energy[r][c] += z
    # fall
    for reprod_tree in reprod_trees:
        r, c = reprod_tree
        for dr, dc in drdc:
            nr, nc = r + dr, c + dc
            if nr < 0 or nc < 0 or nr >= N or nc >= N:
                continue
            trees[nr][nc].appendleft(1)

answer = 0
for r in range(N):
    for c in range(N):
        answer += len(trees[r][c])
print(answer)