#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N;
short Line[3];
int prevMin[3];
int prevMax[3];
int dx[3] = { -1,0,1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	priority_queue<int> pq;

	while (N--)
	{
		int a;
		cin >> a;

		if (a == 0)
		{
			if (pq.size() == 0)
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}

		}
		else
		{
			pq.push(a);
		}
	}
}