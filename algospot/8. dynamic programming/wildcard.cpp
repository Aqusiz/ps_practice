#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
// 앞에서부터 한 글자씩 비교
bool wildcard(const string& pattern, const string& s) {
    if(pattern.size() == 0)
        return (s.size() == 0);
    if(pattern.compare("*") == 0)
        return true;
    if(pattern.compare("?") == 0 && s.size() == 1)
        return true;
    if(pattern.compare(s) == 0)
        return true;
    if(pattern[0] != s[0] && pattern[0] != '?' && pattern[0] != '*')
        return false;

    string new_p(pattern, 1);
    if(pattern[0] == s[0] || pattern[0] == '?') {
        string new_s(s, 1);
        return wildcard(new_p, new_s);
    }

    bool ret = false;
    for(int i = 0; i < s.size(); i++) {
        string new_s(s, i);
        ret = ret || wildcard(new_p, new_s);
    }

    return ret;
}
// 메모이제이션 없는 완전 탐색
bool match(const string& w, const string& s) {
    int pos = 0;
    // 앞에서부터 한글자씩 비교
    while(pos < w.size() && pos < s.size() && (w[pos] == '?' || w[pos] == s[pos]))
        pos++;
    // w의 끝까지 비교가 끝난 경우, w와 s의 길이가 같으면 true 아니면 false
    if(pos == w.size())
        return pos == s.size();
    // *을 만난 경우, 길이가 0인 문자열부터 하나씩 대응해보며 하나라도 true면 true 반환
    if(w[pos] == '*') {
        for(int i = 0; pos + i <= s.size(); i++) {
            if(match(w.substr(pos+1), s.substr(pos+i)))
                return true;
        }
    }
    // 모든 케이스에 속하지 않는 경우 false
    return false;
}
// 메모이제이션 있는 완전 탐색: O(n^3)
// 위 함수에서, w와 s는 항상 원래의 W, S의 접미사(suffix)이므로, 가능한 경우의 수는 각각 101개씩 => 101 * 101 크기의 배열에 모두 저장 가능
int dp[101][101];
string W, S;
bool match2(int w, int s) {
    int& ret = dp[w][s];
    if(ret != -1) return ret;
    // 첫 번째 *를 찾을 때까지 앞에서부터 한 글자씩 비교
    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        w++; s++;
    }
    // wildcard 패턴을 끝까지 탐색한 경우, s도 끝까지 탐색 성공한 경우만 true, 아니면 false
    if(w == W.size()) return ret = (s == S.size());
    // *을 만난 경우
    if(W[w] == '*') {
        // *에 대응되는 글자가 0글자인 경우부터 끝까지 비교
        for(int skip = 0; skip + s <= S.size(); skip++) {
            if(match2(w+1, s+skip))
                return ret = 1;
        }
    }
    return ret = 0;
}
// match2 최적화: O(n^2)
// 함수 내에서 반복문으로 해결되는 부분들을 모두 반복문 없는 재귀호출로 변경하여 최적화
bool match3(int w, int s) {
    int& ret = dp[w][s];
    if(ret != -1) return ret;
    // 최적화 1
    if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
        return ret = match3(w+1, s+1);
    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*') {
        // 최적화 2
        // 매 단계에서 *에 아무 글자도 대응시키지 않을 것인지, 아니면 한 글자씩 추가하면서 대응되는지 재귀호출로 비교
        if(match3(w+1, s) || 
            (s < S.size() && match3(w, s+1)))
            return ret = 1;
    }
    return ret = 0;
}

int main() {
    int C, n;
    cin >> C;
    for(int c = 0; c < C; c++) {
        cin >> W;
        cin >> n;
        memset(dp, -1, 101*101);
        for(int i = 0; i < n; i++) {
            cin >> S;
            if(match2(0, 0)) cout << S << '\n';
        }
    }
    return 0;
}