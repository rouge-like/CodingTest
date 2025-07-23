#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> dirX = { 1,0,-1,0 };
vector<int> dirY = { 0,1,0,-1 };

int n;

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

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y, int* cnt)
{
	if (visited[x][y])
		return;

	visited[x][y] = true;

	if (!map[x][y])
		return;

	*cnt += 1;

	for (int i = 0; i < 4; i++)
	{
		int dx = x + dirX[i];
		int dy = y + dirY[i];

		if (dx < 0 || dy < 0 || dx >= n || dy >= n)
			continue;

		if (map[dx][dy] && visited[dx][dy] == false)
		{
			dfs(map, visited, dx, dy, cnt);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<vector<int>> map(n, vector<int>(n, 0));
	vector<vector<bool>> visited(n, vector<bool>(n, 0));
	vector<int> answer;
	for (int i = 0; i < n; i++)
	{
		string A;
		cin >> A;

		for (int j = 0; j < A.length(); j++)
		{
			map[i][j] = A[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			dfs(map, visited, i, j, &cnt);
			if (cnt != 0)
				answer.push_back(cnt);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (auto it = answer.begin(); it != answer.end(); it++)
	{
		cout << *it << "\n";
	}
}