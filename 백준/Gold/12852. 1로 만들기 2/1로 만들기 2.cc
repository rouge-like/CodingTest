#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N;
vector<pair<int,int>> dp(1000001);

int make(int c)
{
	if (c == 1) return 0;

	if (dp[c].first) return dp[c].first;

	int token = 0;
	int d = c - 1;
	token = make(c - 1) + 1;

	if (c % 3 == 0)
	{
		int tmp = make(c / 3) + 1;

		if (token > tmp)
		{
			token = tmp;
			d = c / 3;
		}
	}
	if (c % 2 == 0)
	{
		int tmp = make(c / 2) + 1;

		if (token > tmp)
		{
			token = tmp;
			d = c / 2;
		}
	}
	dp[c] = {token, d};
	return token;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int ans = make(N);

	cout << ans << "\n";

	int idx = N;

	while (idx != 1)
	{
		cout << idx << " ";
		idx = dp[idx].second;
	}
	cout << "1";
}