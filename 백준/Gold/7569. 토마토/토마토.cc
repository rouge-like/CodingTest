#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point 
{
    int z, y, x;
};

int m, n, h;
vector<vector<vector<int>>> grid;

int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };

queue<Point> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    grid.resize(h, vector<vector<int>>(n, vector<int>(m)));
    
    int unripe_tomatoes = 0;
    for (int i = 0; i < h; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            for (int k = 0; k < m; ++k) 
            {
                cin >> grid[i][j][k];
                if (grid[i][j][k] == 1) 
                {
                    q.push({i, j, k});
                } else if (grid[i][j][k] == 0) 
                {
                    unripe_tomatoes++;
                }
            }
        }
    }

    if (unripe_tomatoes == 0) 
    {
        cout << 0;
        return 0;
    }

    int days = -1;
    while (!q.empty()) 
    {
        days++;
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) 
        {
            Point current = q.front();
            q.pop();

            for (int j = 0; j < 6; ++j) 
            {
                int nz = current.z + dz[j];
                int ny = current.y + dy[j];
                int nx = current.x + dx[j];

                if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                

                if (grid[nz][ny][nx] == 0) 
                {
                    grid[nz][ny][nx] = 1;
                    q.push({nz, ny, nx});
                }
            }
        }
    }

    bool all_ripe = true;
    for (int i = 0; i < h; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            for (int k = 0; k < m; ++k) 
            {
                if (grid[i][j][k] == 0) 
                {
                    all_ripe = false;
                    break;
                }
            }
            if (!all_ripe) break;
        }
        if (!all_ripe) break;
    }

    if (all_ripe) 
    {
        cout << days;
    } 
    else 
    {
        cout << -1;
    }

    return 0;
}
