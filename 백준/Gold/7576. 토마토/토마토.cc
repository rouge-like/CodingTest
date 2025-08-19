#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int m, n;
vector<vector<int>> grid(1001, vector<int>(1001));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			grid[i][j] = a;

			if (a == 1)
			{
				q1.push({ i, j });
				visited[i][j] = true;
			}
		}
	}

	int cnt = 0;
	queue<pair<int, int>>* currentQ = &q1;
	queue<pair<int, int>>* nextQ = &q2;

	while (!q1.empty() || !q2.empty())
	{
		if (currentQ->empty())
		{
			queue<pair<int, int>>* tmp = nextQ;
			nextQ = currentQ;
			currentQ = tmp;
			cnt += 1;
		}

		int r = currentQ->front().first;
		int c = currentQ->front().second;

		currentQ->pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = c + dx[i];
			int ny = r + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (visited[ny][nx] || grid[ny][nx] != 0)
				continue;

			visited[ny][nx] = true;
			grid[ny][nx] = 1;
			nextQ->push({ ny,nx });
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (cnt == -1)
			break;
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 0)
			{
				cnt = -1;
				break;
			}
		}
	}

	cout << cnt;
}