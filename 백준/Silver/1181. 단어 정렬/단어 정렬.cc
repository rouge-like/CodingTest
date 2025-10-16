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
	vector<string> dict;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		dict.push_back(a);
	}

	sort(dict.begin(), dict.end(), [](string a, string b) -> bool
	{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	});

	string last;
	for (auto a : dict)
	{
		if (last != a)
			cout << a << "\n";
		
		last = a;
	}
}