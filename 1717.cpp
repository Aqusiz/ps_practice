#include <iostream>
#include <vector>

using namespace std;

int n, m;
int s[1000001], s_size[1000001];

int find_set(int n) {
    if(s[n] == n) return n;

    s[n] = find_set(s[n]);
    return s[n];
}

void union_set(int a, int b) {
    int a_root = find_set(a);
    int b_root = find_set(b);

    if(s_size[a_root] > s_size[b_root]) {
        s[b_root] = a_root;
        s_size[a_root] += s_size[b_root];
    }
    else {
        s[a_root] = b_root;
        s_size[b_root] += s_size[a_root];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int op, a, b, a_root, b_root;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        s[i] = i;
        s_size[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        switch (op)
        {
        case 0:
            union_set(a, b);
            break;
        case 1:
            a_root = find_set(a);
            b_root = find_set(b);
            cout << ((a_root == b_root) ? "YES" : "NO") << '\n';
            break;
        default:
            break;
        }
    }
}