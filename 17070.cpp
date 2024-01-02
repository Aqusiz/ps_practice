#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, y, x, state, cnt = 0;
    vector<vector<int> > tile;
    // st = [(y, x, state), ...], state: 0(horizontal), 1(vertical), 2(diagonal)
    stack<pair<pair<int, int>, int> > st;

    cin >> n;
    tile = vector<vector<int> >(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> tile[i][j];
    }

    st.push(make_pair(make_pair(0, 1), 0));
    while(!st.empty()) {
        y = st.top().first.first;
        x = st.top().first.second;
        state = st.top().second;
        st.pop();
        if(y == n-1 && x == n-1) {
            cnt++;
            continue;
        }
        if((state == 0 || state == 2) && x+1 < n && tile[y][x+1] == 0)
            st.push(make_pair(make_pair(y, x+1), 0));
        if((state == 1 || state == 2) && y+1 < n && tile[y+1][x] == 0)
            st.push(make_pair(make_pair(y+1, x), 1));
        if(y+1 < n && x+1 < n && tile[y][x+1] + tile[y+1][x+1] + tile[y+1][x] == 0)
            st.push(make_pair(make_pair(y+1, x+1), 2));
    }
    cout << cnt << '\n';

    return 0;
}