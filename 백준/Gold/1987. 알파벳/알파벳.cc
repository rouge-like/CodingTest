#include <iostream>
#include <string>
#include <vector>

using namespace std;

int R, C;
vector<string> mp(20);
vector<bool> visited(26);
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt;

void dfs(int y, int x, int token)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;

        int current = mp[ny][nx] - 'A';

        if (visited[current]) continue;

        visited[current] = true;
        cnt = max(cnt, token + 1);
        dfs(ny, nx, token + 1);
        visited[current] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> mp[i];
    }
        
    int start = mp[0][0] - 'A';
    visited[start] = true;
    dfs(0, 0, 0);
    cnt++;
    cout << cnt;
    return 0;
}