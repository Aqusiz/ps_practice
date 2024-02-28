import sys
sys.setrecursionlimit(10001)
input = sys.stdin.readline
pre_order = []

while True:
    line = input()
    if line == "":
        break
    pre_order.append(int(line))

def solve(pre_order):
    """
    convert pre ordered traversal into post ordered one and return
    """
    if len(pre_order) <= 1:
        return pre_order
    elif len(pre_order) == 2:
        return pre_order[::-1]
    
    root = pre_order[0]
    left_subtree = []
    right_subtree = []
    
    for node in pre_order[1:]:
        if node < root:
            left_subtree.append(node)
        else:
            right_subtree.append(node)
    
    return solve(left_subtree) + solve(right_subtree) + [root]

print(*solve(pre_order), sep='\n')