#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> g[100001];

void dfs(vector<bool>& visited, int current, int& cnt)
{
	if (visited[current])
		return;

	visited[current] = true;
	cnt += 1;

	for (int i = 0; i < g[current].size(); i++)
	{

		dfs(visited, g[current][i], cnt);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[b].push_back(a);
	}

	vector<int> cnt(n + 1);
	int mx = 0;

	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		vector<bool> visited(n + 1);
		dfs(visited, i, count);

		cnt[i] = count;

		if (count > mx)
			mx = count;
	}

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == mx)
			cout << i << " ";
	}
}