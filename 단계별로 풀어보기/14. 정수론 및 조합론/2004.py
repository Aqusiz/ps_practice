def count(n, m):
    counter = 0
    devider = m
    while True:
        if devider <= n:
            counter += (n // devider)
            devider *= m
        else:
            break
    return counter

n, m = map(int, input().split())
n_2 = count(n, 2)
n_5 = count(n, 5)
m_2 = count(m, 2)
m_5 = count(m, 5)
nm_2 = count(n-m, 2)
nm_5 = count(n-m, 5)

print(min(n_2 - (m_2 + nm_2), n_5 - (m_5 + nm_5)))