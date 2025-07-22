#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string A;
	cin >> A;

	int sum = 0;
	for (char c : A)
	{
		int a = c - '0';

		sum += a;
	}
	cout << sum;
}