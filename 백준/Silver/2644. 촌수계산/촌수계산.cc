#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


void dfs(int current, int target, int cnt, vector<vector<int>>& r, vector<bool>& visited, int& out)
{
	if (current == target) 
	{
		out =  cnt;
		return;
	}

	visited[current] = true;

	for (int next : r[current])
	{
		if (!visited[next])
			dfs(next, target, cnt + 1, r, visited, out);
	}

	visited[current] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;

	vector<vector<int>> r(101);
	vector<bool> visited(101, false);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		r[x].push_back(y);
		r[y].push_back(x);
	}
	int ans = -1;

	dfs(a, b, 0, r, visited, ans);
	cout << ans;

}