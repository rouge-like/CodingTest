#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> dp(12);
int T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 3; i < 12; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}