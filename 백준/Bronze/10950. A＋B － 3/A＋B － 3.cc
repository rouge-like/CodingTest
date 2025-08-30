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
	
	cin >> T;
	while(T--)
	{
		cin >> n >> m;

		cout << n + m << "\n";
	}
}