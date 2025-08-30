#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
vector<int> ns;
vector<int> visited(10, 0);
vector<int> g;

void dfs(int c)
{
	visited[c] = 1;
	g.push_back(c);

	if (g.size() == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ns[g[i]] << " ";
		
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
				dfs(i);
		}
	}
	visited[c] = 0;
	g.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ns.push_back(a);
	}

	sort(ns.begin(), ns.end());

	for (int i = 0; i < n; i++)
		dfs(i);
}