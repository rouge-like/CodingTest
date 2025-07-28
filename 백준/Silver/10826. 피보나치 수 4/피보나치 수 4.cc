#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
string add(string a, string b)
{
	string r = "";
	int c = 0;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.size() < b.size()) 
		a += '0';
	while (b.size() < a.size()) 
		b += '0';

	for (int i = 0; i < a.size(); i++) {
		int sum = (a[i] - '0') + (b[i] - '0') + c;
		r += (sum % 10) + '0';
		c = sum / 10;
	}

	if (c) 
		r += c + '0';

	reverse(r.begin(), r.end());
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> dp;
	dp.push_back("0");
	dp.push_back("1");

	for (int i = 2; i <= n; i++)
	{
		dp.push_back(add(dp[i - 1], dp[i - 2]));
	}

	cout << dp[n];
}