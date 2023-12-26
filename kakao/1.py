# 2023 kakao internship
# AC

def solution(friends, gifts):
    answer = 0
    f_idx = {}
    n = len(friends)
    gift_mat = [[0 for _ in range(n)] for _ in range(n)]
    gift_level = [0 for _ in range(n)]
    
    for i in range(n):
        f_idx[friends[i]] = i
    
    for gift in gifts:
        fr, to = gift.split(" ")
        fr_idx, to_idx = f_idx[fr], f_idx[to]
        gift_mat[fr_idx][to_idx] += 1
        gift_level[fr_idx] += 1
        gift_level[to_idx] -= 1
    
    for i in range(n):
        temp = 0
        for j in range(n):
            if i == j:
                continue
            if gift_mat[i][j] > gift_mat[j][i]:
                temp += 1
            elif gift_mat[i][j] == gift_mat[j][i] and gift_level[i] > gift_level[j]:
                temp += 1
        
        if answer < temp:
            answer = temp
        
    return answer