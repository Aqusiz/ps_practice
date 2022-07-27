a, b = map(int, input().split())
c = int(input())

a = a + int(c/60)
b = b + c%60

if (b > 59):
    a = a + int(b/60)
    b = b%60
if (a > 23):
    a = a%24

print(str(a) + " " + str(b))