#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int inDeg[1001] = {0,};
vector<int> adj[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count, prev, curr;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> count;
        cin >> prev;
        for(int j = 1; j < count; j++) {
            cin >> curr;
            inDeg[curr]++;
            adj[prev].push_back(curr);
            prev = curr;
        }
    }

    queue<int> q;
    vector<int> order;

    for(int i = 1; i <= n; i++) {
        if(inDeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        curr = q.front(); q.pop();
        order.push_back(curr);
        for(vector<int>::iterator next = adj[curr].begin(); next != adj[curr].end(); next++) {
            inDeg[*next]--;
            if(inDeg[*next] == 0) q.push(*next);
        }
    }

    if(order.size() == n) {
        for(int i = 0; i < n; i++) cout << order[i] << '\n';
    } else {
        cout << "0\n";
    }

    return 0;
}