#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, S, E;
    int arr[2001];
    bool pel[2001][2001] = {false,};

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        pel[i][i] = true;   // an array of size 1 is pelindrome
    }

    for(int i = 0; i < N-1; i++) {
        // an array of size 2 is pelindrome if values of the array are the same
        if(arr[i] == arr[i+1]) pel[i][i+1] = true;
    }
    for(int gap = 2; gap < N; gap++) {
        for(int i = 0; i < N - gap; i++) {
            // an array [i, i+gap] is pelindrome
            // if arr[i] == arr[i+gap] and array [i+1, i+gap-1] is pelindrome
            if(arr[i] != arr[i + gap]) continue;
            if(pel[i+1][i+gap-1]) pel[i][i+gap] = true;
            else pel[i][i+gap] = false;
        }
    }

    cin >> M;
    for(int tc = 0; tc < M; tc++) {
        cin >> S >> E;
        if(S <= E) cout << pel[S-1][E-1] << '\n';
        else cout << pel[E-1][S-1] << '\n';
    }
    return 0;
}