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
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int w = v[0] * n;
	for (int i = 1; i < n; i++)
	{
		int tmp = v[i] * (n - i);
		if (w < tmp)
		{
			w = tmp;
		}
	}

	cout << w;
}