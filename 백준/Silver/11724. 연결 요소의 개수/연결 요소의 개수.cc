#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


void dfs(int current, vector<vector<int>>& r, vector<bool>& visited)
{
	visited[current] = true;

	for (int next : r[current])
	{
		if (!visited[next])
			dfs(next, r, visited);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges(10004);
	vector<bool> visited(10004);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i, edges, visited);
		}
	}
	cout << cnt;
}