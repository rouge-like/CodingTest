#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	v.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	
	unordered_map<int, int> cnt;
	int l = 0;
	int ans = 0;
	for (int r = 0; r < n; r++)
	{
		cnt[v[r]]++;

		while (cnt.size() > 2) 
		{
			cnt[v[l]]--;
			if (cnt[v[l]] == 0)	cnt.erase(v[l]);
			l++;
		}

		ans = max(ans, r - l + 1);
	}

	cout << ans;
	return 0;
}