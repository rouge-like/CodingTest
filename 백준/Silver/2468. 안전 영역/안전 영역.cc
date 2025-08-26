#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> grid(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, false));
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int mxDepth = 100;
void dfs(int y, int x, int depth)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (visited[ny][nx] || grid[ny][nx] <= depth) continue;

		dfs(ny, nx, depth);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
			//mxDepth = max(mxDepth, grid[i][j]);
		}
	}
 
	int mxCnt = 0;

	for (int d = 0; d < mxDepth; d++)
	{
		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			fill(visited[i].begin(), visited[i].end(), false);
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j] && grid[i][j] > d)
				{
					dfs(i, j, d);
					cnt++;
				}
			}
		}

		mxCnt = max(mxCnt, cnt);
	}

	cout << mxCnt;
}