target_string = input()
n = len(target_string)
bomb = input()
l = len(bomb)
st = []

idx = 0
while idx < n:
    st.append(target_string[idx])
    idx += 1
    
    if len(st) < l or st[-1] != bomb[-1]:
        continue
    if "".join(st[-l:]) == bomb:
        for _ in range(l):
            st.pop()

answer = "".join(st)
print(answer if len(answer) != 0 else "FRULA")