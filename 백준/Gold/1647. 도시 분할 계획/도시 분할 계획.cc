#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <cmath>


using namespace std;

int n, m;
int parent[100001];

int find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}
void unite(int a, int b) 
{
	a = find(a);
	b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
struct road 
{
	int s, e, w;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<road> roads(m);
	for (int i = 0; i < m; i++)
	{
		cin >> roads[i].s >> roads[i].e >> roads[i].w;
	}

	sort(roads.begin(), roads.end(), [](road& x, road& y) { return x.w < y.w; });

	for (int i = 1; i <= n; i++) parent[i] = i;
	int total = 0;
	int maxCost = 0;

	for (auto& r : roads) 
	{
		if (find(r.s) != find(r.e)) 
		{
			unite(r.s, r.e);
			total += r.w;
			maxCost = max(maxCost, r.w);
		}
	}

	cout << total - maxCost;
	return 0;
}