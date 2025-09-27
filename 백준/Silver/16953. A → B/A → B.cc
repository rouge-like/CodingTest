#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

long long A, B;
long long ans = LLONG_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	queue<long long> q;

	q.push(A);

	long long cnt = 1;
	while (q.size())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			long long cur = q.front(); q.pop();

			if (cur == B) 
			{
				ans = min(ans, cnt);
				break;
			}
			else if (cur > B)
			{
				continue;
			}

			q.push(cur * 2);
			q.push(cur * 10 + 1);
		}
		cnt++;
	}

	if (ans != LLONG_MAX) cout << ans;
	else cout << -1;
}