#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> h(100001, vector<int>(2));
vector<int> Ids;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	h.resize(N, vector<int>(2));
	for (int i = 0; i < N; i++)
	{
		cin >> h[i][0] >> h[i][1];
	}

	sort(h.begin(), h.end(),
		[](const vector<int>& L, const vector<int>& R) {
			if (L[1] != R[1]) return L[1] < R[1];
			return L[0] < R[0];
		});

	int cnt = 0;
	int end = 0;

	for (auto& p : h)
	{
		if (p[0] >= end)
		{
			cnt++;
			end = p[1];
		}
	}

	cout << cnt;
}