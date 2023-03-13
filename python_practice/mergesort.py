def mergesort(arr):
    def sort(st, ed):
        # list의 크기가 1이라면, 이미 정렬된 list로 간주하고 반환
        if(ed - st < 2):
            return
        mid = (st + ed) // 2
        # 왼쪽 반 정렬
        sort(st, mid)
        # 오른쪽 반 정렬
        sort(mid, ed)
        # 병합
        merge(st, mid, ed)

    def merge(st, mid, ed):
        temp_arr = []   # 정렬된 순서로 저장해 둘 임시 list
        i, j = st, mid
        while i < mid and j < ed:
            if(arr[i] < arr[j]):
                temp_arr.append(arr[i])
                i += 1
            else:
                temp_arr.append(arr[j])
                j += 1
        while i < mid:
            temp_arr.append(arr[i])
            i += 1
        while j < ed:
            temp_arr.append(arr[j])
            j += 1
        # 임시 list에 저장된 순서대로 원래 list에 적용
        for k in range(st, ed):
            arr[k] = temp_arr[k - st]

    return sort(0, len(arr))

n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
mergesort(arr)
print(arr)