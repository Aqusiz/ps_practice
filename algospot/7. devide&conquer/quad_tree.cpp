// https://www.algospot.com/judge/problem/read/QUADTREE
// devide & conquer
#include <iostream>
#include <vector>

using namespace std;
// my code
string flipped_quad_tree(string qt) {
    if(qt.compare("w") == 0) return "w";
    if(qt.compare("b") == 0) return "b";

    int idx = 1;
    vector<string> v;
    while(v.size() < 4) {
        if(qt[idx] == 'w' || qt[idx] == 'b') {
            v.push_back(qt.substr(idx, 1));
            idx++;
        } else {
            v.push_back(flipped_quad_tree(qt.substr(idx)));
            idx += v.back().size();
        }
    }
    return "x" + v[2] + v[3] + v[0] + v[1];
}
// more simple code in the book
string reverse(string::iterator& it) {
    char head = *it;
    it++;
    if(head == 'b' || head == 'w') return string(1, head);

    string upper_left = reverse(it);
    string upper_right = reverse(it);
    string lower_left = reverse(it);
    string lower_right = reverse(it);

    return "x" + lower_left + lower_right + upper_left + upper_right;
}

int main() {
    int C;
    string s;
    // string::iterator it;
    cin >> C;
    for(int c = 0; c < C; c++) {
        cin >> s;
        cout << flipped_quad_tree(s) << '\n';
        // it = s.begin();
        // cout << reverse(it) << '\n';
    }
    return 0;
}