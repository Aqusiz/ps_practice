#include <iostream>
using namespace std;

string preorder(char root, char *left, char *right) {
    string ans;
    int root_idx = (int)(root - 'A');
    if(root == '.') return "";

    ans += root;
    return ans + preorder(left[root_idx], left, right) + preorder(right[root_idx], left, right);
}

string inorder(char root, char *left, char *right) {
    string ans;
    int root_idx = (int)(root - 'A');
    if(root == '.') return "";

    ans += root;
    return inorder(left[root_idx], left, right) + ans + inorder(right[root_idx], left, right);
}

string postorder(char root, char *left, char *right) {
    string ans;
    int root_idx = (int)(root - 'A');
    if(root == '.') return "";

    ans += root;
    return postorder(left[root_idx], left, right) + postorder(right[root_idx], left, right) + ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char temp;
    int N;
    char left[30], right[30];
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        cin >> left[(int)(temp - 'A')] >> right[(int)(temp - 'A')];
    }
    cout << preorder('A', left, right) << endl;
    cout << inorder('A', left, right) << endl;
    cout << postorder('A', left, right) << endl;

    return 0;
}