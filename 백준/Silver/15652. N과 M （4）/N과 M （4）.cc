#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
vector<int> visited(9, 0);
vector<int> g;

void dfs(int c)
{
	visited[c] = 1;
	g.push_back(c);

	if (g.size() == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << g[i] << " ";
		
		}
		cout << "\n";
	}
	else
	{
		for (int i = c ; i <= n; i++)
		{
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
		dfs(i + 1);
}