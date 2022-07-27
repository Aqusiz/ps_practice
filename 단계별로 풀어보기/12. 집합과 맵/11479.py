S = input()
substring_set = set()

for length in range(0, len(S)):
    for start_index in range(0, len(S) - length):
        substring_set.add(S[start_index:start_index + length + 1])

print(len(substring_set))