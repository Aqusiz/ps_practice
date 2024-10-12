# 회전(zip)
arr = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
print("arr")
print(*arr, sep="\n", end="\n")
# 시계 90도 (== 반시계 270도)
arr_90 = list(map(list, zip(*arr[::-1])))
print("arr_90")
print(*arr_90, sep="\n")
# 시계/반시계 180도
arr_180 = [a[::-1] for a in arr[::-1]]
print("arr_180", *arr_180, sep="\n")
# 시계 270도 (== 반시계 90도)
arr_270 = [x[::-1] for x in list(map(list, zip(*arr[::-1])))[::-1]]
print("arr_270", *arr_270, sep="\n")
# 회전(인덱싱) - 정사각형
arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
n = 3
# 시계 90도
arr_90 = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        arr_90[j][n - i - 1] = arr[i][j]
print("arr_90", *arr_90, sep="\n")
# 시계 180도
arr_180 = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        arr_180[n - i - 1][n - j - 1] = arr[i][j]
print("arr_180", *arr_180, sep='\n')
# 시계 270도
arr_270 = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        arr_270[n - 1 - j][i] = arr[i][j]
print("arr_270", *arr_270, sep='\n')


arr = [1, 2, 3, 4]
visited = [0] * len(arr)  # visited도 전역으로 둬도 됨


def permutations(n, new_arr):
    global arr
    # 순서 상관 0, 중복 X
    if len(new_arr) == n:
        print(new_arr)
        return
    for i in range(len(arr)):
        if not visited[i]:
            visited[i] = 1
            permutations(n, new_arr + [arr[i]])
            visited[i] = 0


permutations(2, [])

arr = [1, 2, 3, 4]

# 현재 인덱스 +1 만큼을 매개변수로 계속 넘겨주어야함
# 순서가 상관없고 중복 불가이기 때문에 현재 인덱스보다 같거나 작은 인덱스는 볼 필요가 없기 때문
def combinations(n, new_arr, c):
    # 순서 상관 X, 중복 X
    if len(new_arr) == n:
        print(new_arr)
        return
    for i in range(c, len(arr)):
        combinations(n, new_arr + [arr[i]], i + 1)


combinations(2, [], 0)