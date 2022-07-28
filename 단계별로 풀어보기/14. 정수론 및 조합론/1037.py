number = int(input())
factors = list(map(int, input().split()))
max_factor = 0
min_factor = int(2**31 - 1)

for factor in factors:
    if factor > max_factor:
        max_factor = factor
    if factor < min_factor:
        min_factor = factor
print(max_factor * min_factor)