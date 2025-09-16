#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
char mp[55][55];
int visited[55][55];
int dy[4] = {1,0,-1,0};
int dx[4] = { 0,1,0, -1 };
int cnt;

void BFS(int sy, int sx)
{
    fill(&visited[0][0], &visited[0][0] + 55 * 55, 0);

    queue<pair<int, int>> q;

    q.push({ sy, sx });
    visited[sy][sx] = 1;
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (mp[ny][nx] == 'W' || visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
            cnt = max(cnt, visited[y][x] + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < M; j++)
        {
            mp[i][j] = a[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mp[i][j] == 'L')
                BFS(i, j);
        }
    }
    cout << cnt - 1;
    return 0;
}