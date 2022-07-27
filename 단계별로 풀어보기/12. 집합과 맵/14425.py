N, M = map(int, input().split())
dictionary = set()
count = 0
for i in range(N):
    dictionary.add(input())

for i in range(M):
    word = input()
    if word in dictionary:
        count += 1

print(count)