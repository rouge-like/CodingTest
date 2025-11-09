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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<int> l(n);
	for (int i = 0; i < n; i++)
		cin >> l[i];

	int left = 0;
	int right = n - 1;
	int mn = 2e9;
	int a = l[left];
	int b = l[right];
	while (left < right)
	{
		int sum = l[left] + l[right];
		if (abs(mn) > abs(sum))
		{
			mn = sum;
			a = l[left];
			b = l[right];
		}
		if (sum > 0)
		{
			right -= 1;
		}
		else
		{
			left += 1;
		}
	}

	cout << a << " " << b;
	return 0;
}