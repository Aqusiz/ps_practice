# Find GCD by Euclidian Algorithm
def euc(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a
# Find integer sqrt
def sqrt(N):
    for i in range(N):
        if (i+1)**2 > N:
            return i
# find and return list of devisors of N
def find_devisor(N):
    devisors = list()
    for i in range(2, sqrt(N)+1):
        if N % i == 0:
            devisors.append(i)
    for devisor in devisors[:]:
        new_devisor = N // devisor
        if new_devisor not in devisors:
            devisors.append(new_devisor)
    devisors.sort()
    devisors.append(N)
    return devisors


N = int(input())
numbers = list()
diff = list()
answer = ""

for i in range(N):
    numbers.append(int(input()))
# Find all differences between numbers
for i in range(N - 1):
    for j in range(i + 1, N):
        diff.append(abs(numbers[i] - numbers[j]))
# Find GCD of all differences
gcd = diff[0]
for i in range(1, len(diff)):
    gcd = euc(gcd, diff[i])
# Find devisors of GCD
devisors = find_devisor(gcd)
for devisor in devisors:
    answer += str(devisor) + " "
print(answer.strip())