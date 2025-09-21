#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int n;
vector<int> v;
vector<int> ret;

void dfs(int num)
{
	if (ret.size() == 6)
	{
		for (int i : ret)
		{
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i < v.size(); i++)
	{
		ret.push_back(v[i]);
		dfs(i + 1);
		ret.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		v.clear();
		ret.clear();

		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			int c;
			cin >> c;
			v.push_back(c);
		}

		dfs(0);

		cout << "\n";
	}
}