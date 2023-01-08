#include <iostream>
using namespace std;
int N;
int map[64][64];

string quad_tree(int n, int a, int b) {     //a, b == offset of i, j
    int flag0 = 1, flag1 = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[a+i][b+j] != 0) flag0 = 0;
            if(map[a+i][b+j] != 1) flag1 = 0;
        }
    }

    if(flag0) return "0";
    if(flag1) return "1";
    
    return "(" + quad_tree(n/2, a, b) + quad_tree(n/2, a, b + n/2) + quad_tree(n/2, a + n/2, b) + quad_tree(n/2, a + n/2, b + n/2) + ")";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char temp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> temp;
            map[i][j] = (int)(temp - '0');
        }
    }

    cout << quad_tree(N, 0, 0) << endl;

    return 0;
}