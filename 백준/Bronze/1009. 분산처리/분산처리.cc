#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;

		int ret = 1;

		for (int i = 0; i < b; i++)
		{
			ret = ret * a;
			ret = ret % 10;
		}
		if (ret == 0) ret = 10;
		cout << ret << "\n";
	}
}