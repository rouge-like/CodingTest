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

	string A;
	getline(cin, A);
		
	bool inWord = false;
	int cnt = 0;

	for (char c : A)
	{
		if (c == ' ')
		{
			if (inWord)
			{
				inWord = false;
			}
		}
		else
		{
			if (!inWord)
			{
				inWord = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}