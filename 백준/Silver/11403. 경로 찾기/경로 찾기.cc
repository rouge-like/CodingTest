#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>


using namespace std;

int n;
vector<vector<int>> v(101, vector<int>(101, 0));

vector<vector<int>> dp(101, vector<int>(101, 0));

void bfs(int start)
{
	vector<int> visited(101);

	queue<int> q;

	q.push(start);

	while (q.size())
	{
		int c = q.front(); q.pop();

		for (int i = 0; i < n; i++)
		{
			if (!v[c][i]) continue;
			if (visited[i]) continue;

			visited[i] = 1;
			dp[start][i] = 1;
			q.push(i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bfs(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}