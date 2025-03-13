import math

H, W, N, M = map(int, input().split())
print(math.ceil(W / (M + 1)) * math.ceil(H / (N + 1)))
