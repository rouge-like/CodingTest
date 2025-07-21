#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
vector<pair<int, int>> dir = { {1,0},{-1,0},{0,1}, {0,-1} };

void bfs(vector<vector<int>>& g) 
{
	queue<pair<int,int>> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<int>> dist(n, vector<int>(m, 0));

	dist[0][0] = 1;

	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (pair<int,int> p : dir)
		{
			int nx = x + p.first;
			int ny = y + p.second;

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) 
				continue;

			if (g[nx][ny] == 0 || visited[nx][ny]) 
				continue;

			q.push({nx, ny});
			visited[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}

	cout << dist[n - 1][m - 1];
}

void dfs (vector<vector<int>>& edeges, vector<bool>& visited, int current)
{
	cout << current + 1 << " ";
	visited[current] = true;

	for (int i = 0; i < edeges[current].size(); i++)
	{
		if (!visited[edeges[current][i]])
		{
			dfs(edeges, visited, edeges[current][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> p(n);
	vector<pair<int, int>> path = { {0,0} };
	for (int i = 0; i < n; i++)
	{
		string A;
		cin >> A;
		for (char c : A)
		{
			p[i].push_back(c - '0');
		}
	}

	bfs(p);
}