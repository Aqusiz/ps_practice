import sys
import heapq
input = sys.stdin.readline
INF = 987654321

def dijkstra(board):
    N = len(board)
    pq = []
    dist = [[INF for _ in range(N)] for _ in range(N)]
    dist[0][0] = board[0][0]
    heapq.heappush(pq, (board[0][0], 0, 0))
    while pq:
        curr_w, y, x = heapq.heappop(pq)
        for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            ny, nx = y + dy, x + dx
            if ny < 0 or ny>= N or nx < 0 or nx >= N: continue
            if dist[ny][nx] > curr_w + board[ny][nx]:
                dist[ny][nx] = curr_w + board[ny][nx]
                heapq.heappush(pq, (dist[ny][nx], ny, nx))
    return dist[N-1][N-1]

t = 1
while True:
    N = int(input())
    if N == 0: break
    board = []
    for _ in range(N):
        line = list(map(int, input().split()))
        board.append(line)
    print(f"Problem {t}: {dijkstra(board)}")
    t += 1