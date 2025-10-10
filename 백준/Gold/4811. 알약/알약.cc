#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n;
long long dp[34][34];

long long f(long long one, long long half)
{
	if (one < 0 || half < 0) return 0;
	if (one == 0 && half == 0) return 1;
	if (dp[one][half] != -1) return dp[one][half];

	long long token = 0;

	token += f(one - 1, half + 1);
	token += f(one, half - 1);

	dp[one][half] = token;

	return token;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> n;

		if (n == 0) break;

		fill(&dp[0][0], &dp[0][0] + 34 * 34, -1);

		cout << f(n, 0) << "\n";
	}
}