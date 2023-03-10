#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
// merge every two same blocks near
void merge(vector<int>& v) {
    vector<int>::iterator cur, next;
    for(cur = v.begin(); cur != v.end();) {
        next = cur + 1;
        if(next != v.end() && *cur == *next) {
            cur = v.erase(cur);
            *cur *= 2;
        }
        cur++;
    }
}

vector<vector<int> > up(vector<vector<int> > b) {
    vector<int> v;
    vector<int>::iterator cur, next;
    // for each column
    for(int j = 0; j < N; j++) {
        v = vector<int>();
        // push all elements in the column
        for(int i = 0; i < N; i++) {
            if(b[i][j] == 0) continue;
            v.push_back(b[i][j]);
        }
        // merge
        merge(v);
        // re-allocate in the column
        for(int i = 0; i < N; i++) {
            if(i < v.size()) b[i][j] = v[i];
            else b[i][j] = 0;
            if(b[i][j] > ans) ans = b[i][j];    // check maximum
        }
    }
    return b;
}
vector<vector<int> > down(vector<vector<int> > b) {
    vector<int> v;
    vector<int>::iterator cur, next;
    // for each column
    for(int j = 0; j < N; j++) {
        v = vector<int>();
        // push all elements in the column, from bottom
        for(int i = N-1; i >= 0; i--) {
            if(b[i][j] == 0) continue;
            v.push_back(b[i][j]);
        }
        // merge
        merge(v);
        // re-allocate in the column
        for(int i = 0; i < N; i++) {
            if(i < v.size()) b[N-1-i][j] = v[i];
            else b[N-1-i][j] = 0;
            if(b[i][j] > ans) ans = b[i][j];    // check maximum
        }
    }
    return b;
}
vector<vector<int> > left(vector<vector<int> > b) {
    vector<int> v;
    vector<int>::iterator cur, next;
    // for each row
    for(int i = 0; i < N; i++) {
        v = vector<int>();
        // push all elements in the row
        for(int j = 0; j < N; j++) {
            if(b[i][j] == 0) continue;
            v.push_back(b[i][j]);
        }
        // merge
        merge(v);
        // re-allocate in the row
        for(int j = 0; j < N; j++) {
            if(j < v.size()) b[i][j] = v[j];
            else b[i][j] = 0;
            if(b[i][j] > ans) ans = b[i][j];    // check maximum
        }
    }
    return b;
}
vector<vector<int> > right(vector<vector<int> > b) {
    vector<int> v;
    vector<int>::iterator cur, next;
    // for each row
    for(int i = 0; i < N; i++) {
        v = vector<int>();
        // push all elements in the row, from right
        for(int j = N-1; j >= 0; j--) {
            if(b[i][j] == 0) continue;
            v.push_back(b[i][j]);
        }
        // merge
        merge(v);
        // re-allocate in the row
        for(int j = 0; j < N; j++) {
            if(j < v.size()) b[i][N-1-j] = v[j];
            else b[i][N-1-j] = 0;
            if(b[i][j] > ans) ans = b[i][j];    // check maximum
        }
    }
    return b;
}

void simulate(vector<vector<int> > b, int depth) {
    if(depth == 5) return;
    
    simulate(up(b), depth+1);
    simulate(down(b), depth+1);
    simulate(left(b), depth+1);
    simulate(right(b), depth+1);
}

int main() {
    int x;
    vector<vector<int> > board;
    cin >> N;
    for(int i = 0; i < N; i++) {
        board.push_back(vector<int>());
        for(int j = 0; j < N; j++) {
            cin >> x;
            board[i].push_back(x);  
        }
    }
    simulate(board, 0);
    cout << ans << '\n';
    return 0;
}