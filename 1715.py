import sys
import heapq
input = sys.stdin.readline

N = int(input())
deck = [0 for _ in range(N)]
for i in range(N):
    deck[i] = int(input())
heapq.heapify(deck)

ans = 0
while len(deck) > 1:
    s1 = heapq.heappop(deck)
    s2 = heapq.heappop(deck)
    ans += s1 + s2
    heapq.heappush(deck, s1 + s2)

print(ans)