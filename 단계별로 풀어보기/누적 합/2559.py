N, K = map(int, input().split())
numbers = list(map(int, input().split()))
psum = [0 for _ in range(N)]
# psum[i] = numbers[i-K+1] + ... + numbers[i]
psum[0] = numbers[0]
for i in range(1, K):
    psum[i] = psum[i-1] + numbers[i]

for i in range(K, N):
    psum[i] = psum[i-1] + numbers[i] - numbers[i - K]
# except for first K-1 arrays
print(max(psum[K-1:]))