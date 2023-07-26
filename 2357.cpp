#include <iostream>
#include <vector>
#define INF 1000000001
#define MAX 1
#define MIN 0
#define MID(a, b) (a + b)/2
using namespace std;

void seg_init(vector<int>& seg, vector<int>& arr, int maxmin, int pos, int st, int ed) {
    if(st == ed) seg[pos] = arr[st];
    else {
        seg_init(seg, arr, maxmin, pos*2, st, MID(st, ed));
        seg_init(seg, arr, maxmin, pos*2 + 1, MID(st, ed) + 1, ed);
        seg[pos] = (maxmin == MAX) ? max(seg[pos*2], seg[pos*2 + 1]) : min(seg[pos*2], seg[pos*2 + 1]);
    }
}

int seg_get(vector<int>& seg, int maxmin, int pos, int l, int r, int st, int ed) {
    if(r < st || l > ed) return (maxmin == MAX) ? MIN : INF;
    else if (l <= st && r >= ed) return seg[pos];

    int l_sub, r_sub;
    l_sub = seg_get(seg, maxmin, pos*2, l, r, st, MID(st, ed));
    r_sub = seg_get(seg, maxmin, pos*2 + 1, l, r, MID(st, ed) + 1, ed);
    return (maxmin == MAX) ? max(l_sub, r_sub) : min(l_sub, r_sub);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, a, b;
    vector<int> arr, minseg, maxseg;
    cin >> N >> M;
    arr = vector<int>(N);
    minseg = vector<int>(N*4 + 1);
    maxseg = vector<int>(N*4 + 1);

    for(int i = 0; i < N; i++) cin >> arr[i];
    seg_init(maxseg, arr, MAX, 1, 0, N-1);
    seg_init(minseg, arr, MIN, 1, 0, N-1);

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << seg_get(minseg, MIN, 1, a-1, b-1, 0, N-1) << ' ' << seg_get(maxseg, MAX, 1, a-1, b-1, 0, N-1) << '\n';
    }

    return 0;
}