#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int sy, sx, ey, ex;
char a[301][301];
int visited[301][301];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void BFS(int sy, int sx)
{

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];


    queue<pair<int, int>> q;
    q.push({ sy, sx });
    int cnt = 0;
    a[sy][sx] = 0;
    while (a[ey][ex] != '0')
    {
        cnt += 1;
        queue<pair<int, int>> buffer;

        while (q.size())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;

                visited[ny][nx] = cnt;

                if (a[ny][nx] == '0')
                {
                    q.push({ ny,nx });
                }
                else
                {
                    a[ny][nx] = '0';

                    buffer.push({ ny,nx });
                }

            }
        }

        q = buffer;
    }

    cout << visited[ey][ex];
    return 0;
}