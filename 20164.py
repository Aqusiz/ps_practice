def count_odds(n):
    ret = 0
    for i in n:
        if int(i) % 2 == 1:
            ret += 1
    return ret

def solve(n, minmax):
    if len(n) == 1:
        return count_odds(n)
    if len(n) == 2:
        new_n = str(int(n[0]) + int(n[1]))
        return count_odds(n) + solve(new_n, minmax)
    
    l = len(n)
    ret = 987654321 if minmax == 0 else -1
    for i in range(1, l - 1):
        for j in range(1, l - i):
            num1, num2, num3 = n[:i], n[i:i + j], n[i + j:]
            result = count_odds(num1) + count_odds(num2) + count_odds(num3) + solve(str(int(num1) + int(num2) + int(num3)), minmax)
            if minmax == 0 and result < ret:
                ret = result
            elif minmax == 1 and result > ret:
                ret = result

    return ret

N = input()
print(solve(N, 0), solve(N, 1))