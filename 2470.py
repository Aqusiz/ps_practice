n = int(input())
arr = list(map(int, input().split()))
arr.sort()

l = 0
r = n - 1
sum_of_two = 2000000001

while l < r:
    temp = arr[r] + arr[l]
    if abs(temp) < sum_of_two:
        sum_of_two = abs(temp)
        ll = l
        rr = r
    if temp > 0:
        r = r - 1
    elif temp < 0:
        l = l + 1
    else:
        break

print(arr[ll], arr[rr])