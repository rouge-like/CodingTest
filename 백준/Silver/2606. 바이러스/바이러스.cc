#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int cnt = -1;

void dfs (vector<vector<int>>& edeges, vector<bool>& visited, int current)
{
	cnt++;
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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> p(n);
	vector<bool> visited(n, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		p[--a].push_back(--b);
		p[b].push_back(a);
	}

	dfs(p, visited, 0);

	cout << cnt;
}