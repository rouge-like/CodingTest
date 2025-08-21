#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<int>> visited;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
void dfs(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (visited[ny][nx] || grid[ny][nx])
            continue;

        dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    grid.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            grid[i][j] = a;
        }
    }
    int cnt = 0;
    while (true)
    {
        for (int i = 0; i < n; i++)
            fill(visited[i].begin(), visited[i].begin() + m, 0);
        dfs(0, 0);

        vector<pair<int, int>> cheese;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int airCnt = 0;

                if (grid[i][j] == 1)
                {

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = i + dy[k];
                        int nx = j + dx[k];

                        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                            continue;
                        if (visited[ny][nx]) airCnt++;
                    }

                    if (airCnt >= 2)
                    {
                        cheese.push_back({ i,j });
                    }
                }
            }
        }
        
        if (cheese.empty())
            break;

        cnt++;
        for (auto pos : cheese)
        {
            grid[pos.first][pos.second] = 0;
        }
    }

    cout << cnt;
}
