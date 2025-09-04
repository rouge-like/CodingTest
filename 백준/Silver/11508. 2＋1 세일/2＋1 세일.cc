#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> h(100001);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	h.resize(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
	}

	sort(h.begin(), h.end(), [](int a, int b) -> bool {
		return a > b;
		});

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (i % 3 == 2)
			continue;
		cnt += h[i];
	}

	cout << cnt;
}