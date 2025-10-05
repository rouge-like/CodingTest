#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;


	while (N--)
	{
		int k;
		cin >> k;

		priority_queue<int> maxPQ;
		priority_queue<int, vector<int>, greater<int>> minPQ;
		map<int, int> cnt;

		for(int i = 0; i < k; i++)
		{
			char cmd;
			int num;

			cin >> cmd >> num;

			if (cmd == 'I')
			{
				maxPQ.push(num);
				minPQ.push(num);
				cnt[num]++;
			}
			else if (cmd == 'D')
			{
				if (cnt.empty()) continue;

				if (num == 1)
				{
					while (!maxPQ.empty() && cnt.find(maxPQ.top()) == cnt.end()) maxPQ.pop();

					if (!maxPQ.empty())
					{
						cnt[maxPQ.top()]--;

						if (cnt[maxPQ.top()] == 0) cnt.erase(maxPQ.top());

						maxPQ.pop();
					}
				}
				else if (num == -1)
				{
					while (!minPQ.empty() && cnt.find(minPQ.top()) == cnt.end()) minPQ.pop();

					if (!minPQ.empty())
					{
						cnt[minPQ.top()]--;
						if (cnt[minPQ.top()] == 0) cnt.erase(minPQ.top());
						minPQ.pop();
					}
				}
			}
		}

		while (!maxPQ.empty() && cnt.find(maxPQ.top()) == cnt.end()) maxPQ.pop();
		while (!minPQ.empty() && cnt.find(minPQ.top()) == cnt.end()) minPQ.pop();

		if (cnt.empty()) cout << "EMPTY\n";
		else cout << maxPQ.top() << " " << minPQ.top() << "\n";
	}

}