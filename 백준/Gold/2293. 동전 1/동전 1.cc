#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n, k;
int dp[10001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		for (int j = a; j <= k; j++)
		{
			dp[j] += dp[j - a];
		}
	}

	cout << dp[k];
}