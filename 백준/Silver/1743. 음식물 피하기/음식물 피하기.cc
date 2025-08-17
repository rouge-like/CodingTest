#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int n, m, k;
vector<vector<int>> grid(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int dfs(int r, int c)
{
	int size = 1;

	visited[r][c] = true;

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr > n || nc > m)
			continue;

		if (!visited[nr][nc] && grid[nr][nc] == 1)
		{
			size += dfs(nr, nc);
		}
	}

	return size;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;

		grid[r][c] = 1;
	}

	int mx = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (!visited[i][j] && grid[i][j] == 1)
				mx = max(mx, dfs(i, j));
		}
	}

	cout << mx;
}