T = int(input())
for i in range(T):
    clothes = dict()
    n = int(input())
    for j in range(n):
        name_of_cloth, type_of_cloth = input().split()
        if clothes.get(type_of_cloth):
            clothes[type_of_cloth] += 1
        else:
            clothes[type_of_cloth] = 1
    answer = 1
    for v in clothes.values():
        answer *= (v + 1)
    print(answer-1)