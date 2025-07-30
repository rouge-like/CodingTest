#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	vector<int> v;
	vector<int> dp;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		v.push_back(a);
	}

	dp.push_back(1);

	for (int i = 1; i < n; i++)
	{
		int mx = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && mx < dp[j] + 1)
			{
				mx = dp[j] + 1;
			}
		}
		dp.push_back(mx);
	}

	cout << *max_element(dp.begin(), dp.end());
}