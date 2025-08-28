#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 987654321;
int N, M;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	vector<vector<int>> grid;
	grid.resize(N, vector<int>(M, 0));
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string str;
		getline(cin, str);

		for (int j = 0; j < M; j++)
		{
			grid[i][j] = str[j] - '0';
		}
	}

	vector<vector<int>> dist;
	dist.resize(N, vector<int>(M, MAX));
	dist[0][0] = 0;

	deque<pair<int,int>> dq;
	dq.push_back({ 0,0 });

	int breakCost = N * M + 1;

	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();

		if (y == N - 1 && x == M - 1)
			break;
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (grid[ny][nx] == 1)
			{
				if (dist[ny][nx] > dist[y][x] + breakCost)
				{
					dist[ny][nx] = dist[y][x] + breakCost;
					dq.push_back({ ny, nx });
				}
			}
			else
			{
				if (dist[ny][nx] > dist[y][x] + 1)
				{
					dist[ny][nx] = dist[y][x] + 1;
					dq.push_front({ ny,nx });
				}
			}
		}
	}

	cout << dist[N - 1][M - 1] / (N * M);
}