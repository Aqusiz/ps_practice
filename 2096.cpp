#include <iostream>
#include <vector>
using namespace std;

int n;
int tile[100001][3];
int dp_min[2][3], dp_max[2][3];

int main() {
    // input & init
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> tile[i][j];
    for(int j = 0; j < 3; j++)
        dp_min[0][j] = dp_max[0][j] = tile[0][j];
    // solve: dp
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            dp_min[i % 2][j] = INT32_MAX;
            dp_max[i % 2][j] = -1;
        }
        for(int j = 0; j < 3; j++) {
            for(int k = -1; k <= 1; k++) {
                if(j + k < 0 || j + k > 2) continue;
                dp_min[i % 2][j] = min(dp_min[i % 2][j], dp_min[(i - 1) % 2][j + k] + tile[i][j]);
                dp_max[i % 2][j] = max(dp_max[i % 2][j], dp_max[(i - 1) % 2][j + k] + tile[i][j]);
            }
        }
    }
    cout << max(dp_max[(n-1) % 2][0], max(dp_max[(n-1) % 2][1], dp_max[(n-1) % 2][2])) << " ";
    cout << min(dp_min[(n-1) % 2][0], min(dp_min[(n-1) % 2][1], dp_min[(n-1) % 2][2])) << '\n';
    return 0;
}