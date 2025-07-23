#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> dirX = { 1,0,-1,0 };
vector<int> dirY = { 0,1,0,-1 };

void bfs(int m, int n, int k)
{
	vector<vector<int>> map(m, vector<int>(n, 0));
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	queue<pair<int, int>> pos;

	queue<pair<int, int>> path;

	int cnt = 0;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		pos.push({ x,y });
	}



	while (!pos.empty()) 
	{
		if (!visited[pos.front().first][pos.front().second])
		{
			path.push(pos.front());
			visited[pos.front().first][pos.front().second] = true;
			cnt++;
		}

		pos.pop();

		while (!path.empty())
		{
			int x = path.front().first;
			int y = path.front().second;
			path.pop();
			for (int i = 0; i < 4; i++)
			{
				int dx = x + dirX[i];
				int dy = y + dirY[i];

				if (dx < 0 || dy < 0 || dx >= m || dy >= n)
					continue;

				if (map[dx][dy] && visited[dx][dy] == false)
				{
					path.push({ dx,dy });
					visited[dx][dy] = true;
				}
			}
		}
	}

	cout << cnt << "\n";
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, m, n, k;

	cin >> t;

	while (t--)
	{
		cin >> m >> n >> k;

		bfs(m, n, k);
	}

}