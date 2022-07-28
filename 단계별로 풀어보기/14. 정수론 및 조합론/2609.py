A, B = map(int, input().split())
GCD = 0
for i in range(1, min(A, B) + 1):
    if A % i == 0 and B % i == 0:
        GCD = i
LCM = GCD * (A // GCD) * (B // GCD)

print(GCD)
print(LCM)