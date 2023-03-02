#include <iostream>
#include <queue>
using namespace std;

void dfs(int v, int* to, bool* visited, deque<int>& path) {
    int next = to[v];
    visited[v] = true;
    path.push_back(v);
    // a vertex only has one out-going edge -> no need for loop
    if(!visited[next]) {
        dfs(next, to, visited, path);
    }
    else {
        // find cycle in path
        while(!path.empty()) {
            if(path.front() == next) break;
            path.pop_front();
        }
    }
}

int find_answer(int n, int* to) {
    int ret = n;
    deque<int> path;
    bool* visited = new bool[n+1];
    for(int i = 1; i <= n; i++) visited[i] = false;

    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        path = deque<int>();
        dfs(i, to, visited, path);
        ret -= path.size(); // size of path == size of cycle found in dfs
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, n;
    int to[100001];

    cin >> T;
    for(int tc = 0; tc < T; tc++) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> to[i];
        cout << find_answer(n, to) << '\n';
    }
    return 0;
}