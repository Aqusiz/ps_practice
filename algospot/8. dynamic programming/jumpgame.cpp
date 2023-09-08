#include <iostream>
#include <vector>

using namespace std;

int n, board[100][100];
int dp[100][100];
// 완전 탐색을 하는 재귀 호출 알고리즘
// jump(y, x) => (y, x)에서부터 맨 마지막 칸까지 도달할 수 있는지 여부를 반환
bool jump(int y, int x) {
    // base case 1. board 밖으로 벗어난 경우
    if(y >= n || x >= n) return false;
    // base case 2. 도착점에 도착한 경우
    if(y == n-1 && x == n-1) return true;

    int jump_size = board[y][x];
    return jump(y + jump_size, x) || jump(y, x + jump_size);
}
// 완전 탐색의 경우, 가능한 경로의 수는 매우 많지만 주어지는 입력의 수는 고작 10000개가 최대
// 비둘기집의 원리에 의해, 중복 호출은 반드시 존재
// 메모이제이션을 적용한 알고리즘
int jump2(int y, int x) {
    // base case
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;

    int& ret = dp[y][x];
    // 이미 계산된 적 있는 경우, 즉시 반환
    if(ret != -1) return ret;
    
    int jump_size = board[y][x];
    return ret = (jump2(y + jump_size, x) || jump2(y, x + jump_size));
}

int main() {

}