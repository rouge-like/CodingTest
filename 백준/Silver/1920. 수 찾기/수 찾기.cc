#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;
	vector<int> A;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	cin >> M;
	vector<int> B;
	for (int i = 0; i < M; i++)
	{
		int b;
		cin >> b;
		B.push_back(b);
	}

	sort(A.begin(), A.end());

	for (int x : B)
	{
		int r, l;
		r = N - 1;
		l = 0;
		int find = 0;

		while (r >= l)
		{
			int mid = (r + l) / 2;

			if (x == A[mid])
			{
				find = 1;
				break;
			}
			else if (x > A[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << find << "\n";
	}

}