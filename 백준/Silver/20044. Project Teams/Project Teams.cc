#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < 2 * n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int c = 2e9;

	for (int i = 0; i < n; i++)
	{
		c = min(c, v[i] + v[2 * n - 1 - i]);
	}

	cout << c;
}