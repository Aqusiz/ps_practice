# 2023 kakao internship
# Fail

def simulate(coin, hands, cards, goal, r):
    if len(cards) == 2:
        return r + 1
    
    h = len(hands)
    ret = r
    card1, card2 = cards[0], cards[1]
    new_cards = cards[2:]
    
    # 동전 안쓰는 경우
    for i in range(h-1):
        for j in range(i+1, h):
            if hands[i] + hands[j] == goal:
                new_hands = hands[:i] + hands[i+1:j] + hands[j+1:]
                ret = max(ret, simulate(coin, new_hands, new_cards, goal, r+1))
    # 동전 1개 쓰는 경우
    if coin >= 1:
        for i in range(h):
            if hands[i] + card1 == goal or hands[i] + card2 == goal:
                new_hands = hands[:i] + hands[i+1:]
                ret = max(ret, simulate(coin - 1, new_hands, new_cards, goal, r+1))
    # 동전 2개 쓰는 경우
        
        
    return ret

def solution(coin, cards):
    answer = 0
    n = len(cards)
    hands = cards[:n//3]
    cards = cards[n//3:]
    answer = simulate(coin, hands, cards, n+1, 1)
    return answer