n = int(input())
parent_of = list(map(int, input().split()))
deleted = int(input())

is_leaf = [True for _ in range(n)]
is_leaf[deleted] = False
for i in range(n):
    p = parent_of[i]
    # skip if already checked
    if not is_leaf[i]:
        continue
    # check all ancestors as False
    # until the root or the deleted node
    while p != -1 and p != deleted:
        is_leaf[p] = False
        p = parent_of[p]
    # if the deleted node is the one of ancestors, this node is also deleted
    if p == deleted:
        is_leaf[i] = False

print(sum(is_leaf))