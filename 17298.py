N = int(input())
A = list(map(int, input().split()))
answers = [-1 for _ in range(N)]
st = []

for i in range(N):
    while st and A[st[-1]] < A[i]:
        answers[st.pop()] = A[i]
    st.append(i)
    
print(*answers, sep=" ")