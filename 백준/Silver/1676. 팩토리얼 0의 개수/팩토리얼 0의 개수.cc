#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) 
	{
		cnt += n / i;
	}

	cout << cnt << '\n';
	return 0;
}