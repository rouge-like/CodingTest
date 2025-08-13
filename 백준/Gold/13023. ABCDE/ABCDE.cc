#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> R(2000);
vector<int> Friends;
vector<bool> Visited(2000, false);
bool Finished = false;

void dfs()
{
	if (Finished)
		return;

	if (Friends.size() == 5)
	{
		Finished = true;
		cout << "1";
		return;
	}

	int current = Friends.back();

	for (int next : R[current])
	{
		if (!Visited[next])
		{
			Friends.push_back(next);
			Visited[next] = true;
			dfs();
		}
	}
	Friends.pop_back();
	Visited[current] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		R[a].push_back(b);
		R[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		Friends.push_back(i);
		Visited[i] = true;
		dfs();
	}

	if (!Finished)
		cout << "0";
}