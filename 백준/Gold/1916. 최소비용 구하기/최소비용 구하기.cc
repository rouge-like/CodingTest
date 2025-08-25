#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const long long MAX = 1e15;
vector<long long> dist;
vector<bool> visited;
vector<vector<pair<int, int>>> costs;
int N, M;
int End;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	dist.resize(N + 1, MAX);
	visited.resize(N + 1, false);
	costs.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end, cost;

		cin >> start >> end >> cost;

		costs[start].push_back({ end, cost });
	}

	int start;
	cin >> start >> End;
	dist[start] = 0;
	
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		 
	pq.push({ 0, start });

;	while (!pq.empty())
	{
		int cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (visited[current]) continue;

		visited[current] = true;

		if (current == End) break;


		for (auto pair : costs[current])
		{
			int next = pair.first;
			int dc = pair.second;

			if (dist[next] > cost + dc)
			{
				dist[next] = cost + dc;
				pq.push({ dist[next], next });
			}
		}
	}

	cout << dist[End];
}