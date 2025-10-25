#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[501][501];
bool visited[501][501];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int result = 0;

void dfs(int y, int x, int depth, int sum) {
    if (depth == 4) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx]) continue;

        visited[ny][nx] = true;
        dfs(ny, nx, depth + 1, sum + board[ny][nx]);
        visited[ny][nx] = false;
    }
}

void checkTShape(int y, int x) {
    // ㅗ, ㅜ, ㅏ, ㅓ
    int shape[4][4][2] = {
        {{0,0},{0,1},{0,-1},{-1,0}}, // ㅗ
        {{0,0},{0,1},{0,-1},{1,0}},  // ㅜ
        {{0,0},{1,0},{-1,0},{0,1}},  // ㅏ
        {{0,0},{1,0},{-1,0},{0,-1}}  // ㅓ
    };

    for (int s = 0; s < 4; s++) {
        int sum = 0;
        bool valid = true;
        for (int i = 0; i < 4; i++) {
            int ny = y + shape[s][i][0];
            int nx = x + shape[s][i][1];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                valid = false;
                break;
            }
            sum += board[ny][nx];
        }
        if (valid) result = max(result, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;

            checkTShape(i, j); // ㅗ 모양 따로 검사
        }
    }

    cout << result;
}
