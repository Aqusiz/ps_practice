N = int(input())
card_list = list(map(int, input().split()))
M = int(input())
number_list = list(map(int, input().split()))

card_dict = dict()
for card in card_list:
    if card not in card_dict:
        card_dict[card] = 1
    else:
        card_dict[card] += 1

answer = ""
for number in number_list:
    if number in card_dict:
        answer += str(card_dict[number]) + " "
    else:
        answer += "0 "

print(answer.strip())