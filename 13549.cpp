// 0-1 bfs
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int main() {
    int N, K, curr;
    int d[MAX];
    deque<int> dq;  // use deque
    for(int i = 0; i < MAX; i++) {
        d[i] = INT32_MAX;
    }

    cin >> N >> K;
    d[N] = 0;
    dq.push_front(N);
    while(!dq.empty()) {
        curr = dq.front();
        dq.pop_front();
        if(curr == K) break;
        // 0-weight: push front
        if(curr * 2 < MAX && d[curr * 2] > d[curr]) {
            d[curr * 2] = d[curr];
            dq.push_front(curr * 2);
        }
        // 1-weight: push back
        if(curr + 1 < MAX && d[curr + 1] > d[curr] + 1) {
            d[curr+1] = d[curr] + 1;
            dq.push_back(curr + 1);
        }
        if(curr - 1 >= 0 && d[curr - 1] > d[curr] + 1) {
            d[curr - 1] = d[curr] + 1;
            dq.push_back(curr - 1);
        }
    }
    cout << d[K] << '\n';
    return 0;
}