from collections import deque
A, B, C = map(int, input().split())
Node = (A, B, C)

from_to = ((0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1))
visited = [[False for _ in range(201)] for _ in range(201)]
answer = []

q = deque()
q.append([0, 0, C])
while q:
    cur_node = q.popleft()
    if visited[cur_node[0]][cur_node[1]]:
        continue
    visited[cur_node[0]][cur_node[1]] = True
    
    if cur_node[0] == 0:
        answer.append(C - cur_node[0] - cur_node[1])

    for fr, to in from_to:
        new_node = [cur_node[0], cur_node[1], cur_node[2]]
        if new_node[fr] == 0:
            continue
        if new_node[fr] + new_node[to] > Node[to]:
            new_node[fr] = new_node[fr] + new_node[to] - Node[to]
            new_node[to] = Node[to]
        else:
            new_node[to] = new_node[fr] + new_node[to]
            new_node[fr] = 0
        q.append(new_node)

answer.sort()
print(*answer, sep=" ")