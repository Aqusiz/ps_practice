# python fast read
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
numbers = list(map(int, input().split()))
psum = [0 for _ in range(N+1)]
# make prefix sum array
for i in range(1, N+1):
    psum[i] = psum[i-1] + numbers[i-1]

for _ in range(M):
    i, j = map(int, input().split())
    print(psum[j]-psum[i-1])