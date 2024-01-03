n = int(input())
parent_of = list(map(int, input().split()))
deleted = int(input())

is_leaf = [True for _ in range(n)]
is_leaf[deleted] = False
for i in range(n):
    now = i
    p = parent_of[now]
    # skip if already checked
    if not is_leaf[now]:
        continue
    # check all ancestors as False
    # until the root or the deleted node
    while p != -1 and p != deleted:
        is_leaf[p] = False
        parent_of[now] = parent_of[p]
        p = parent_of[p]
    # if the deleted node is the one of ancestors, this node is also deleted
    if p == deleted:
        is_leaf[now] = False

print(sum(is_leaf))