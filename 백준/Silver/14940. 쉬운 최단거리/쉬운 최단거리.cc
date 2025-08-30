#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
const int MAX = 2e9;
vector<vector<int>> grid(1001, vector<int>(1001, 0));
vector<vector<int>> dist(1001, vector<int>(1001, MAX));
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int y, x = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 2)
			{
				y = i;
				x = j;
			}
			else if (grid[i][j] == 0)
			{
				dist[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> q;

	dist[y][x] = 0;
	q.push({ y,x });
	
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (grid[ny][nx] == 0) continue;

			if (dist[ny][nx] > dist[cy][cx] + 1)
			{
				dist[ny][nx] = dist[cy][cx] + 1;

				q.push({ ny,nx });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == MAX)
				cout  << "-1 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}