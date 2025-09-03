#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int N, K;
vector<int> h(100001);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	h.resize(N);
	for (int i = 1; i <= N; i++)
	{
		cin >> h[N - i];
	}

	int m = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int remain = K - m;
		if (h[i] <= remain)
		{
			int c = remain / h[i];
			m += h[i] * c;
			cnt += c;
		}
	}

	cout << cnt;
}