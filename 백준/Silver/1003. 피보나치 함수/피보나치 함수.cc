#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	vector<pair<int, int>> dp;
	dp.push_back({ 1,0 });
	dp.push_back({ 0,1 });

	for (int i = 2; i < 41; i++)
	{
		dp.push_back({ dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second });
	}
	while (T--)
	{

		int n;
		cin >> n;

		cout << dp[n].first << " " << dp[n].second << "\n";
	}
}