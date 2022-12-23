#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    char a;
    int q, l, r, len;
    int psum[30][200000];

    cin >> S;
    cin >> q;
    len = S.length();
    for(int i = 0; i < len; i++) {
        for(int j = 'a'; j <= 'z'; j++) {
            if (S[i] == j) 
                psum[j-'a'][i] = psum[j-'a'][i-1] + 1;
            else
                psum[j-'a'][i] = psum[j-'a'][i-1];
        }
    }

    for(int i = 0; i < q; i++) {
        cin >> a >> l >> r;
        if(l == 0)
            cout << psum[a-'a'][r] << '\n';
        else
            cout << psum[a-'a'][r] - psum[a-'a'][l-1] << '\n';
    }
}