#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


void bfs(vector<vector<int>>& edeges, vector<bool>& visited, int start) 
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		cout << n + 1 << " ";

		for (int i = 0; i < edeges[n].size(); i++)
		{
			if (!visited[edeges[n][i]])
			{
				q.push(edeges[n][i]);
				visited[edeges[n][i]] = true;
			}
		}
	}
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

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> p(n);
	vector<bool> visited(n, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		p[--a].push_back(--b);
		p[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		sort(p[i].begin(), p[i].end());
	}

	vector<vector<int>> p1(p);
	vector<bool> visited1(visited);

	dfs(p1, visited1, v-1);
	cout << "\n";
	bfs(p, visited, v-1);
}