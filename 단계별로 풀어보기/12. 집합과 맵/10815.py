# set -> implemented by hash table

N = int(input())
cards = set(map(int, input().split()))
M = int(input())
numbers = list(map(int, input().split()))
answer = ""
for number in numbers:
    if number in cards:
        answer = answer + "1 "
    else:
        answer = answer + "0 "

print(answer.strip())