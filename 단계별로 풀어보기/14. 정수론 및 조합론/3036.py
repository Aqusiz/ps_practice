def euc(a, b):
    if a % b == 0:
        return b
    return euc(b, a%b)

N = int(input())
r_list = list(map(int, input().split()))

for i in range(1, N):
    gcd = euc(r_list[0], r_list[i])
    print(str(r_list[0] // gcd) + "/" + str(r_list[i] // gcd))
