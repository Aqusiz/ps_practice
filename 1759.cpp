#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
int vowel[5] = {'a', 'e', 'i', 'o', 'u'};
int chars[16];

bool is_vowel(int c) {
    for(int i = 0; i < 5; i++) {
        if(c == vowel[i]) return true;
    }
    return false;
}

void dfs(int idx, int v_cnt, int c_cnt, string s) {
    if(idx == c) {
        return;
    }
    string new_s = s + (char)chars[idx];
    int new_v = (is_vowel(chars[idx])) ? v_cnt + 1 : v_cnt;
    int new_c = (new_v == v_cnt) ? c_cnt + 1 : c_cnt;

    if(new_s.size() == l && new_v >= 1 && new_c >= 2) {
        cout << new_s << '\n';
        return;
    }

    for(int i = idx+1; i < c; i++) {
        dfs(i, new_v, new_c,  new_s);
    }
}

void solve() {
    for(int i = 0; i <= c - l; i++) {
        dfs(i, 0, 0, "");
    }
}

int main() {
    char temp;
    cin >> l >> c;
    for(int i = 0; i < c; i++) {
        cin >> temp;
        chars[i] = (int)temp;
    }
    sort(chars, chars + c);

    solve();
    return 0;
}