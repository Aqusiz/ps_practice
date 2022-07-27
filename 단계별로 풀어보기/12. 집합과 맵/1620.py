# python fast input = sys.stdin.readline() -> include '\n'
import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
pocketmon_dict = dict()
number_dict = dict()
answer = ""

for i in range(N):
    pocketmon = sys.stdin.readline().rstrip()
    pocketmon_dict[str(i+1)] = pocketmon
    number_dict[pocketmon] = str(i+1)

for i in range(M):
    word = sys.stdin.readline().rstrip()
    if word.isdigit():
        answer += pocketmon_dict.get(word)
    else:
        answer += number_dict.get(word)
    answer += "\n"

print(answer.rstrip())