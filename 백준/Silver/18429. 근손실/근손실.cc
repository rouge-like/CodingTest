#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int n, k;
vector<int> p;
vector<int> ret;
vector<int> visited(10, false);
int sum, cnt;

void dfs()
{
	if (ret.size() == n)
	{
		cnt += 1;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;

		ret.push_back(i);
		visited[i] = true;

		sum += p[i]  - k;
		if (sum >= 0)
			dfs();
		ret.pop_back();
		visited[i] = false;

		sum -= p[i] - k;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		p.push_back(a);
	}
	dfs();
	cout << cnt;
}