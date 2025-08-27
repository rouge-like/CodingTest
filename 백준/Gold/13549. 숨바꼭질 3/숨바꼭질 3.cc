#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N, K;
const int MAX = 987654321;
vector<int> dist(100001, 987654321);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void bfs()
{

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int c = pq.top().second;

		pq.pop();

		if (cost > dist[c]) continue;

		if (c == K)
		{
			cout << dist[K];
			return;
		}

		int nx[3] = { c - 1, c + 1, c * 2 };
		int nt[3] = { 1, 1, 0 };
		for (int i = 0; i < 3; i++)
		{
			int n = nx[i];

			if (n < 0 || n >= 100001) continue;
			
			
			if (dist[n] > cost + nt[i])
			{
				dist[n] = cost + nt[i];
				pq.push({ dist[n], n });
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	pq.push({ 0, N });
	dist[N] = 0;
	bfs();
}