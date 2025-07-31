#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> m;
	for (int i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		m.push_back(a);
	}
	sort(m.begin(), m.end());
	while (next_permutation(m.begin(), m.end()))
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			sum += m[i];
		}
		if (sum == 100)
		{
			for (int i = 0; i < 7; i++)
			{
				cout << m[i] << "\n";
			}
			break;
		}
	}
}