#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> dp(301, vector<int>(3, 0));

	int N;
	cin >> N;

	vector<int> stair;
	stair.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		stair.push_back(a);
	}
	dp[1][1] = stair[1];
	dp[2][1] = stair[2];
	dp[2][2] = stair[1] + stair[2];

	for (int i = 3; i <= N; i++)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + stair[i];
		dp[i][2] = dp[i - 1][1] + stair[i];
	}

	cout << *max_element(dp[N].begin(), dp[N].end());
}