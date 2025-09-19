#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int n;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// 3 5
	bool find = false;
	for (int i = 0; i <= n / 3; i++)
	{
		int s3 = i;
		int s5 = (n - (3 * s3)) / 5;

		if (s3 * 3 + s5 * 5 == n)
		{
			cout << s3 + s5;
			find = true;
			break;
		}
	}
	if (!find)
		cout << "-1";
}