#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N, K;
vector<int> dist(100001, -1);
queue<int> q;

void bfs()
{

	while (!q.empty())
	{
		int c = q.front();
		q.pop();

		if (c == K)
		{
			cout << dist[K];
			return;
		}

		int nx[3] = { c - 1, c + 1, c * 2 };

		for (int i = 0; i < 3; i++)
		{
			int n = nx[i];

			if (n < 0 || n >= 100001 || dist[n] != -1) continue;
				

			dist[n] = dist[c] + 1;
			q.push(n);
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	q.push(N);
	dist[N] = 0;
	bfs();
}