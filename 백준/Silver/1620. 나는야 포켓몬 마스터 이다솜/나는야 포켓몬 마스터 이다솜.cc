#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	map<int, string> dict1;
	map<string, int> dict2;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string A;
		cin >> A;
		dict1[i + 1] = A;
		dict2[A] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		string A;
		cin >> A;
		int num = atoi(A.c_str());

		if (num) 
		{
			cout << dict1[num] << "\n";
		}
		else
		{
			cout << dict2[A] << "\n";
		}
	}
}