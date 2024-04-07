import sys

input = sys.stdin.readline
drdc = ((-1, 0), (1, 0), (0, -1), (0, 1))
R, C, T = map(int, input().split())
A = []
air_cleaner = []
for i in range(R):
    line = list(map(int, input().split()))
    if line[0] == -1:
        air_cleaner.append(i)
    A.append(line)

def diffuse():
    B = [[0]*C for _ in range(R)]
    for r in range(R):
        for c in range(C):
            if A[r][c] < 5:
                continue
            count = 0
            for dr, dc in drdc:
                nr, nc = r + dr, c + dc
                if nr < 0 or nc < 0 or nr >= R or nc >= C or A[nr][nc] == -1:
                    continue
                count += 1
                B[nr][nc] += A[r][c] // 5
            A[r][c] -= count * (A[r][c] // 5)
    for r in range(R):
        for c in range(C):
            A[r][c] += B[r][c]

def _clean_top():
    ac_r = air_cleaner[0]
    for r in range(ac_r-1, 0, -1):
        A[r][0] = A[r - 1][0]
    for c in range(0, C - 1):
        A[0][c] = A[0][c + 1]
    for r in range(0, ac_r):
        A[r][C-1] = A[r+1][C-1]
    for c in range(C-1, 1, -1):
        A[ac_r][c] = A[ac_r][c - 1]
    A[ac_r][1] = 0

def _clean_bottom():
    ac_r = air_cleaner[1]
    for r in range(ac_r+1, R-1):
        A[r][0] = A[r + 1][0]
    for c in range(0, C - 1):
        A[R-1][c] = A[R - 1][c + 1]
    for r in range(R-1, ac_r, -1):
        A[r][C-1] = A[r - 1][C - 1]
    for c in range(C-1, 1, -1):
        A[ac_r][c] = A[ac_r][c - 1]
    A[ac_r][1] = 0

def clean():
    _clean_top()
    _clean_bottom()

for t in range(T):
    diffuse()
    clean()

print(sum(sum(A, [])) + 2)