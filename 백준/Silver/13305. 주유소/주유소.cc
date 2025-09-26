#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector<int> l(100000);
vector<int> o(100000);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> l[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> o[i];
	}

	long long sum = 0;
	long long mn = 0;

	sum = o[0] * l[1];
	mn = o[0];

	for(int i = 1; i < N; i++)
	{
		if (mn > o[i])
		{
			mn = o[i];
		}

		sum += mn * l[i + 1];
	}

	cout << sum;
}