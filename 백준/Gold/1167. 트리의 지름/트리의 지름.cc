#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int V;
vector<vector<pair<int, int>>> E(100001);
vector<bool> Visited(100001, false);
int MaxDist = 0;
int TmpNode = 1;

void dfs(int current, int dist)
{
	Visited[current] = true;

	if (MaxDist <= dist)
	{
		MaxDist = dist;
		TmpNode = current;
	}

	for (pair<int, int> i : E[current])
	{
		if (!Visited[i.first])
		{
			dfs(i.first, dist + i.second);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	for (int i = 0; i < V; i++)
	{
		int u;
		cin >> u;

		while (true)
		{
			int v;
			cin >> v;

			if (v == -1) break;

			int w;
			cin >> w;

			E[u].push_back({ v,w });
		}
	}

	dfs(1, 0);
	
	fill(Visited.begin(), Visited.end(), false);
	MaxDist = 0;

	dfs(TmpNode, 0);

	cout << MaxDist;
}