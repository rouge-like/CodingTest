#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int v, e;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	
	using P = pair<int, int>;
	priority_queue <P, vector<P>, greater<P>> pq;

	vector<vector<P>> costs;
	costs.resize(v + 1);
	for (int i = 0; i < e; i++)
	{
		int idx, end, cost;

		cin >> idx >> end >> cost;
		costs[idx].push_back({ cost, end });
		costs[end].push_back({ cost,idx });
	}

	pq.push({ 0,1 });

	vector<bool> visited(v + 1, false);
	long long c = 0;
	int picked = 0;

	while (!pq.empty() && picked < v)
	{
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (visited[idx]) continue;

		visited[idx] = true;
		c += cost;
		picked++;

		for (auto next : costs[idx])
		{
			int nextIdx = next.second;
			int nextCost = next.first;

			if (visited[nextIdx]) continue;

			pq.push({ nextCost, nextIdx });
		}
	}

	cout << c;
}