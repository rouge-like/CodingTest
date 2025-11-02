#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>


using namespace std;

int n, m;
vector<vector<int>> connection(101, vector<int>(101, 0));
vector<vector<int>> dp(101, vector<int>(101, 0));

void bfs(int start)
{
	vector<int>visited(101, -1);
	visited[start] = 0;

	queue<int>q;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front(); q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (!connection[current][i]) continue;
			if (visited[i] != -1) continue;

			q.push(i);
			visited[i] = visited[current] + 1;
			dp[start][i] = min(visited[i], dp[start][current] + 1);
		}
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
		connection[a][b] = 1;
		dp[a][b] = 1;
		connection[b][a] = 1;
		dp[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}
	
	int min = 2e9;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += dp[i][j];
		}

		if (min > sum)
		{
			min = sum;
			ans = i;
		}
	}

	cout << ans;

	return 0;
}