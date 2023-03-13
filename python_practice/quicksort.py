def quicksort(arr):
    def sort(st, ed):
        # list의 크기가 1이라면, 이미 정렬된 list로 간주하고 반환
        if(ed - st < 2):
            return
        # pivot 설정
        pivot = partition(st, ed)
        # pivot의 왼쪽 정렬
        sort(st, pivot)
        # pivot의 오른쪽 정렬
        sort(pivot, ed)
    # list의 끝 값을 pivot으로 사용
    def partition(st, ed):
        p = st
        for k in range(st, ed-1):
            if(arr[k] < arr[ed-1]):
                arr[k], arr[p] = arr[p], arr[k]
                p += 1
        arr[p], arr[ed-1] = arr[ed-1], arr[p]
        return p

    return sort(0, len(arr))

n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
quicksort(arr)
print(arr)