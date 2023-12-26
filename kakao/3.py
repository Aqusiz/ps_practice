# 2023 kakao internship
# Fail

import itertools

def solution(dice):
    answer = []
    n = len(dice)
    choices = list(itertools.combinations(range(1, n + 1), n // 2))
    return answer

# solution([[1,2,3,4,5,6], [3,3,3,3,4,4], [1,3,3,4,4,4], [1,1,4,4,5,5]])
print(solution([[40, 41, 42, 43, 44, 45], [43, 43, 42, 42, 41, 41], [1, 1, 80, 80, 80, 80], [70, 70, 1, 1, 70, 70]]))