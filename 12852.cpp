#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N, x;
    int *path, *len;
    queue<int> q;
    stack<int> st;

    cin >> N;
    path = new int[N+1];
    len = new int[N+1];
    for(int i = 1; i <= N; i++) {
        path[i] = 0;
        len[i] = 0;
    }
    // bfs
    q.push(N);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        if(x == 1) break;
        if(len[x-1] == 0) {
            len[x-1] = len[x] + 1;
            path[x-1] = x;
            q.push(x-1);
        }
        if(x % 2 == 0 && len[x/2] == 0) {
            len[x/2] = len[x] + 1;
            path[x/2] = x;
            q.push(x/2);
        }
        if(x % 3 == 0 && len[x/3] == 0) {
            len[x/3] = len[x] + 1;
            path[x/3] = x;
            q.push(x/3);
        }
    }
    x = 1;
    cout << len[x] << '\n';
    // build path
    while(x != N) {
        st.push(x);
        x = path[x];
    }
    st.push(x);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}