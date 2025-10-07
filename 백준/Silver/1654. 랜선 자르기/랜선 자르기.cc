#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int K, N;
vector<int> l;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;

	long long mn = 1;
	long long mx = 0;

	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		l.push_back(num);

		if (num > mx) mx = num;
	}

	long long ans;

	while (mn <= mx)
	{
		long long md = (mx - mn) / 2 + mn;

		long long cnt = 0;

		for (int a : l)
		{
			cnt += a / md;
		}

		if (cnt >= N)
		{
			ans = md;
			mn = md + 1;
		}
		else
		{
			mx = md - 1;
		}
	}

	cout << ans;
}