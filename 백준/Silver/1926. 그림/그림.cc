#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> grid(501, vector<int>(501, 0));
vector<vector<int>> visited(501, vector<int>(501, false));
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };

int dfs(int currentX, int currentY)
{
	visited[currentY][currentX] = true;

	int t = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = currentX + dx[i];
		int ny = currentY + dy[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;

		if (visited[ny][nx] || grid[ny][nx] == 0)
			continue;

		t += dfs(nx, ny);
	}
	return t;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			grid[i][j] = a;
		}
	}

	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j] && grid[i][j] == 1)
			{
				cnt++;
				mx = max(mx, dfs(j, i));
			}
		}
	}
	cout << cnt << "\n";
	cout << mx << "\n";
}