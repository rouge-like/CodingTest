#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int T, n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;
		cout << n + m << "\n";

	}
}