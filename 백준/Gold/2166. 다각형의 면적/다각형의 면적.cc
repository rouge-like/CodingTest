#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <cmath>


using namespace std;

int n;
vector<pair<long double, long double>> pos;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}

	pos.push_back(pos.front());
	long double x = 0;
	long double y = 0;

	for (int i = 1; i <= n; i++)
	{
		x += pos[i - 1].first * pos[i].second;
		y += pos[i - 1].second * pos[i].first;
	}    
	cout << fixed;
	cout.precision(1);
	cout << fabsl(x - y) / 2.0;

	return 0;
}