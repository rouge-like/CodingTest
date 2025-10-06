#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; i++) dq.push_back(i);

	int cnt = 0;
	while (M--)
	{
		int target;
		cin >> target;

		int idx = 0;

		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == target)
			{
				idx = i;
				break;
			}
		}


		if (idx <= dq.size() / 2)
		{
			while (dq.front() != target)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else
		{
			while (dq.front() != target)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}

		dq.pop_front();
	}

	cout << cnt << "\n";
}