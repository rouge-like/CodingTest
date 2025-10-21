#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int N;
vector<string> strs1;
vector<string> strs2;
int visited[101][101];
int dy[4] = {1,0,-1,0};
int dx[4] = { 0,1,0,-1 };

void bfs(pair<int,int> start, vector<string>& strs)
{
    deque<pair<int, int>> q;
    q.push_back(start);

    char color = strs[start.first][start.second];

    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop_front();

        int y = cur.first;
        int x = cur.second;

        visited[y][x] = true;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx]) continue;
            if (strs[ny][nx] == color)
            {
                q.push_front({ ny,nx });
            }
        }
    }

}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    strs1.resize(N);
    strs2.resize(N);

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        strs1[i] = a;

        string b;
        for (int j = 0; j < N; j++)
        {
            if (a[j] == 'G')
                b.push_back('R');
            else
                b.push_back(a[j]);
        }

        strs2[i] = b;
    }

    int cnt1 = 0;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                bfs({ i,j }, strs1);
                cnt1++;
            }
        }
    }
    int cnt2 =0;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                bfs({ i,j }, strs2);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2;
}