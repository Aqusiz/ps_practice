# Euclidean algorithm

def euc(A, B):
    if A % B == 0:
        return B
    return euc(B, A%B)

T = int(input())
for i in range(T):
    A, B = map(int, input().split())
    GCD = euc(max(A, B), min(A, B))
    print(GCD * (A // GCD) * (B // GCD))