#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	deque<int> q;

	while (T--)
	{
		string cmd;

		cin >> cmd;

		if (cmd == "push")
		{
			int num;
			cin >> num;
			q.push_back(num);
		}
		else if (cmd == "pop")
		{
			if (q.empty()) cout << "-1" << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (cmd == "size")
		{
			cout << q.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (cmd == "front")
		{
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.front() << "\n";
		}
		else if (cmd == "back")
		{
			if (q.empty()) cout << "-1" << "\n";
			else cout << q.back() << "\n";
		}
	}
	return 0;
}