#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
    int mx = 102;
    vector<vector<int>> map(mx, vector<int>(mx, -1));
    vector<vector<int>> visited(mx, vector<int>(mx, 0));
    
    for(auto& i : rectangle)
    {
        int x1 = i[0] * 2;
        int y1 = i[1] * 2;
        int x2 = i[2] * 2;
        int y2 = i[3] * 2;
        
        for(int x = x1; x <= x2; x++)
        {
            for(int y = y1; y <= y2; y++)
            {
                if (x1 < x && x < x2 && y1 < y && y < y2)
                    map[x][y] = 0;
                else if (map[x][y] != 0)
                    map[x][y] = 1;
            }
        }
    }
    queue<pair<int,int>> q;
    int sx = characterX * 2, sy = characterY * 2;
    int tx = itemX * 2, ty = itemY * 2;

    q.push({sx, sy});
    visited[sx][sy] = 1;
    
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == tx && y == ty)
            return visited[x][y] / 2;

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= mx || ny < 0 || ny  >= mx)
                continue;
            if (map[nx][ny] == 1 && visited[nx][ny] == 0) 
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return 0;
}