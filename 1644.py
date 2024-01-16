N = int(input())
is_prime_number = [True for _ in range(N+1)]
prime_numbers = []
acc_sum = [0]

is_prime_number[0] = is_prime_number[1] = False
for i in range(2, N+1):
    for j in range(2, N//i + 1):
        is_prime_number[i * j] = False
for i in range(2, N+1):
    if is_prime_number[i]:
        prime_numbers.append(i)
for i in range(len(prime_numbers)):
    acc_sum.append(acc_sum[i] + prime_numbers[i])

cnt = 0
i, j = 0, 1
while i < j and j < len(acc_sum):
    value = acc_sum[j] - acc_sum[i]
    if value == N:
        cnt += 1
        j += 1
    elif value < N:
        j += 1
    else:
        i += 1
print(cnt)