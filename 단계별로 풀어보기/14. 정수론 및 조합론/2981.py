N = int(input())
numbers = list()
answer = ""
for i in range(N):
    numbers.append(int(input()))

numbers.sort()
for M in range(2, numbers[1] - numbers[0] + 1):
    check = True
    for i in range(N-1):
        if numbers[i] % M != numbers[i+1] % M:
            check = False
            break
    if check:
        answer += str(M) + " "

print(answer.strip())