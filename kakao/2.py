# 2023 kakao internship
# AC

def solution(edges):
    answer = []
    max_v = 0
    in_edge_cnt = [0 for _ in range(1000001)]
    out_edge_cnt = [0 for _ in range(1000001)]
    
    for edge in edges:
        from_v, to_v = edge
        max_v = max(max_v, from_v, to_v)
        in_edge_cnt[to_v] += 1
        out_edge_cnt[from_v] += 1
    
    new_v = 0   # a number of the generated vertex
    n = 0       # num of all graphs
    d_n = 0     # num of donut graphs
    b_n = 0     # num of bar graphs
    e_n = 0     # num of eight-graphs
    for v in range(1, max_v+1):
        if out_edge_cnt[v] >= 2 and in_edge_cnt[v] == 0:
            new_v = v
            n = out_edge_cnt[v]
        if out_edge_cnt[v] == 0 and (in_edge_cnt[v] == 1 or in_edge_cnt[v] == 2):
            b_n += 1
        if out_edge_cnt[v] == 2 and (in_edge_cnt[v] == 2 or in_edge_cnt[v] == 3):
            e_n += 1
    d_n = n - b_n - e_n
    
    answer = [new_v, d_n, b_n, e_n]
    return answer