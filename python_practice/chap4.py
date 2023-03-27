import string
# 4.2.1
num_list = [[1, 2, 3, [4,5]], [6, 7, 8], 9]
print(num_list[2])
print(num_list[1][1])
print(num_list[0][2:4])
# 4.2.2
A = {2, 4, 5}
B = {1, 2, 2, 1, 10, 4}
C = {3, 3, 3, 4}
print(A & B & C)
print((A | B | C) - A)
# 4.2.3
#name = input()
#num = input()
#print(f"{name[:1]}*{name[2:]}({num[-4:]})님 등록되었습니다.")
# 4.2.4
participant = ['Apeach', 'Ryan', 'Muzi', 'Choonsik', 'Neo', 'Tube']
completion = ['Ryan', 'Muzi', 'Neo', 'Choonsik']
participant = set(participant)
completion = set(completion)
not_comp = list(participant - completion)
print(not_comp)
# 4.2.5
names = ['Apeach', 'Ryan', 'Muzi', 'Choonsik', 'Neo', 'Tube']
names.sort()
# class_dict = dict(enumerate(sorted(names), 1))
class_dict = {i+1: names[i] for i in range(len(names))}
print(class_dict)
# 4.2.6
scores = [85, 96, 78, 88, 81, 92, 73]
sum_of_scores = sum(scores)
sum_of_scores -= (max(scores) + min(scores))
print(sum_of_scores / (len(scores) - 2))
# 4.2.7
str1 = "cat"
str2 = "dog"
str3 = "dcoagt"
str4 = ""
str5 = ""
if len(str1) < len(str2):
    str1, str2 = str2, str1
for i, j in zip(str1, str2):
    str4 += i + j
    str5 += j + i
str4 += str1[len(str2):]
str5 += str1[len(str2):]
print(str3 == str4 or str3 == str5)
# 4.2.8
input_int = 32145
output_list = sorted(list(str(input_int)))
print(output_list)
# 4.2.9
a = 265
b = 112
b_list = list(str(b))
for num in b_list[::-1]:
    print(a*int(num))
print(a*b)
# 4.2.10
participants = {'1월3일' : ['현성', '문정', '현무', '강현'], '2월10일' : ['문정', '강현', '정훈'], '3월7일' : ['현성', '연아', '현무', '지아']}
participants['3월7일'].append('강현')
print(participants)
name = '현성'
print(name in participants['1월3일'])
# 4.2.11
a = 3
n = 4
print([x*3 for x in range(1, n+1)])
# 4.2.12
foods = "ham bread chicken egg".split()
prices = list(map(int, "1200 5000 17000 500".split()))
print(f"Cheapest food: {foods[prices.index(min(prices))]}")
print(f"Most Expensive food: {foods[prices.index(max(prices))]}")
# 4.2.13
input_list = [85, 96, 78, 88, 81, 92, 73]
input_list.remove(max(input_list))
input_list.remove(min(input_list))
print(input_list)
# 4.2.14
#names = list(input().split())
#scores = list(input().split())
#output_list = list(zip(names, scores))
#print(output_list)
# 4.2.15
#print(f"최고 : {names[scores.index(max(scores))]}")
#print(f"최저 : {names[scores.index(min(scores))]}")
# 4.2.16
num_list = [64, 62, 55, 54, 60, 58, 72, 100]
scores_list = []
for idx, value in enumerate(num_list, 1):
    scores_list.append((value, idx))
scores_list.sort()
for i in range(3):
    print(f"{i+1}등 {scores_list[i][1]}번 {scores_list[i][0]}초")
# 4.2.17
words = 'abcdefg'
print(words[::2])
print(words[1::2])
# 4.2.18
results = ['나연', '나연', '가연', '다연', '마연', '나연', '가연', '나연', '다연', '다연']
print([(x, results.count(x)) for x in set(results)])
# 4.2.19
words = 'CAT'
num = 1
table = string.ascii_uppercase + string.ascii_uppercase
words = list(words)
new_words = []
for c in words:
    new_words.append(table[table.find(c) + num])
print("".join(new_words))