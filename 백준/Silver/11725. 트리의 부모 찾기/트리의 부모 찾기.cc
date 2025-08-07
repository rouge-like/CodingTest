#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> edges[100001];
vector<bool> visited(100001, false);
vector<int> parent(100001, 0);

void dfs(int node)
{
	visited[node] = true;

	for (int next : edges[node])
	{
		if (!visited[next])
		{
			parent[next] = node;
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b); 
		edges[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

}