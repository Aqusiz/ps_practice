T = int(input())
for i in range(T):
    A, B = map(int, input().split())
    GCD = 0
    for j in range(1, min(A, B) + 1):
        if A % j == 0 and B % j == 0:
            GCD = j
    print(GCD * (A // GCD) * (B // GCD))