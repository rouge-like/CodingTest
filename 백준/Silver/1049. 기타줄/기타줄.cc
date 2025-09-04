#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<int> h1;
vector<int> h6;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	h1.resize(M, 0);
	h6.resize(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> h6[i] >> h1[i];
	}

	sort(h1.begin(), h1.end());
	sort(h6.begin(), h6.end());

	int remainString = N;
	int cost = 0;

	if (h1[0] * 6 > h6[0])
	{
		cost += remainString / 6 * h6[0];
		remainString %= 6;
	}
	else
	{
		cost += remainString * h1[0];
		remainString = 0;
	}

	if (remainString > 0)
		cost += min(h6[0], h1[0] * remainString);

	cout << cost;
}