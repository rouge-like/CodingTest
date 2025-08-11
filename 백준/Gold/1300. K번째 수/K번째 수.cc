#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

long long N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	int k;
	cin >> k;
	

	long long l = 1;
	long long r = N * N;

	long long ans;

	while (l <= r)
	{
		long long mid = (r - l) / 2 + l;

		long long cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(N, mid / i);
		}

		if (cnt >= k)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	cout << ans;
}