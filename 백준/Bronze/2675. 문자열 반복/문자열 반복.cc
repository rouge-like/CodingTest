#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int cnt;
		string A;
		cin >> cnt >> A;

		for (char c : A)
		{
			for (int j = 0; j < cnt; j++)
			{
				cout << c;
			}
		}

		cout << "\n";
	}
}