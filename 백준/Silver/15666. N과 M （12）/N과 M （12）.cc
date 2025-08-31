#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
vector<int> numbers;
vector<int> visited(10, 0);
vector<int> g;
int last = -1;

void dfs(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << numbers[g[i]] << " ";
		}
		cout << "\n";
	}
	else
	{
		int prev = -1;

		for(int i = 0; i < n; i++)
		{
			if (depth > 0 && numbers[i] < numbers[g.back()]) continue;
			if (prev == numbers[i]) continue;
 			g.push_back(i);
			dfs(depth + 1);
			g.pop_back();
			prev = numbers[i];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		numbers.push_back(a);
	}

	sort(numbers.begin(), numbers.end());
	visited.resize(n, 0);

	dfs(0);
}