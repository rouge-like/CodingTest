#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int n;
vector<int> g;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	g.resize(n);

	vector<int*>tmp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> g[i];
		tmp[i] = &g[i];
	}
	sort(tmp.begin(), tmp.end(), [](const int* a, const int* b)->bool {return *a < *b; });

	int idx = 0;
	int p = *tmp[0];
	for (int i = 0; i < n; i++)
	{
		if (*tmp[i] != p)
			idx++;
		p = *tmp[i];
		*tmp[i] = idx;
	}

	for (int i = 0; i < n; i++)
	{
		cout << g[i] << " ";
	}
}