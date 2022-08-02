N = int(input())
answer = 0
devider = 10
facto = 1
for i in range(2, N+1):
    facto *= i
while True:
    if facto % devider == 0:
        answer += 1
        devider *= 10
    else:
        break
print(answer)