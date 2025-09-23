#include <iostream>
#include <string>
#include <vector>

using namespace std;

int R, C, K;
vector<string> mp;
bool visited[6][6];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt = 0;

void dfs(int y, int x, int token)
{
    if (token == K)
    {
        if (y == 0 && x == C - 1) cnt++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (mp[ny][nx] == 'T') continue;
        if (visited[ny][nx]) continue;

        visited[ny][nx] = true;
        dfs(ny, nx, token + 1);
        visited[ny][nx] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;

    for (int i = 0; i < R; i++)
    {
        string l;
        cin >> l;
        mp.push_back(l);
    }
    visited[R - 1][0] = true;

    dfs(R - 1, 0, 1);

    cout << cnt;

    return 0;
}