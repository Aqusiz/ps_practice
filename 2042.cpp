#include <iostream>
#include <vector>
#define lli long long int
using namespace std;

void init(vector<lli>& seg, vector<lli>& arr, int pos, int l, int r) {
    if(l == r) {
        seg[pos] = arr[l];
    } else {
        init(seg, arr, pos*2, l, (l+r)/2);
        init(seg, arr, pos*2 + 1, (l+r)/2 + 1, r);
        seg[pos] = seg[pos*2] + seg[pos*2 + 1];
    }
}

lli get(vector<lli>& seg, int pos, int l, int r, int st, int ed) {
    if(l > ed || r < st) return 0;
    else if (l <= st && r >= ed) return seg[pos];
    
    lli lsum, rsum;
    lsum = get(seg, pos*2, l, r, st, (st+ed)/2);
    rsum = get(seg, pos*2 + 1, l, r, (st+ed)/2 + 1, ed);
    return lsum + rsum;
}

void update(vector<lli>& seg, int pos, int target, lli v, int st, int ed) {
    if(target < st || target > ed) return;
    if(st == ed) {
        seg[pos] = v;
        return;
    }
    update(seg, pos*2, target, v, st, (st+ed)/2);
    update(seg, pos*2 + 1, target, v, (st+ed)/2 + 1, ed);
    seg[pos] = seg[pos*2] + seg[pos*2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    lli a, b, c;
    vector<lli> arr, seg;

    cin >> N >> M >> K;
    arr = vector<lli>(N);
    seg = vector<lli>(4*N + 1);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init(seg, arr, 1, 0, N-1);
    for(int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        switch (a)
        {
        case 1:
            update(seg, 1, b-1, c, 0, N-1);
            arr[b-1] = c;
            break;
        case 2:
            cout << get(seg, 1, b-1, c-1, 0, N-1) << '\n';
            break;
        default:
            break;
        }
    }

    return 0;
}