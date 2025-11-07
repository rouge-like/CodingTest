#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>


using namespace std;

int v,e;
int s;

vector<int> dist(20001, 3e7);
vector<vector<pair<int, int>>> edges(20001);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	cin >> s;
	s--;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;
		edges[u - 1].push_back({ v - 1, w });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		int c = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[c] < cost) continue;

		for (int i = 0; i < edges[c].size(); i++)
		{
			int next = edges[c][i].first;
			int weight = edges[c][i].second;

			if (dist[next] > cost + weight)
			{
				dist[next] = cost + weight;
				pq.push({ dist[next], next });
			}
		}
	}

	for (int i = 0; i < v; i++)
	{
		if (dist[i] == 3e7) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}