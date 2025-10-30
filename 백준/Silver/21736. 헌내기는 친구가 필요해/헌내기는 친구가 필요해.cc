#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int N, M;
char mp[601][601];
int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };
vector<vector<bool>> visited(601, vector<bool>(601, false));
int ans = 0;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx]) continue;
        if (mp[ny][nx] == 'X') continue;
        if (mp[ny][nx] == 'P') ans++;

        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> N >> M;


    int startY;
    int startX;

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;

        for (int j = 0; j < M; j++)
        {
            if (a[j] == 'I')
            {
                startY = i;
                startX = j;
            }
            mp[i][j] = a[j];
        }
    }

    visited[startY][startX] = true;
    dfs(startY, startX);

    if (ans == 0)
        cout << "TT";
    else
        cout << ans;
}
