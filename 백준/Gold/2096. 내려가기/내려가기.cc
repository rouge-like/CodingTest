#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N;
short Line[3];
int prevMin[3];
int prevMax[3];
int dx[3] = { -1,0,1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> Line[0] >> Line[1] >> Line[2];

	prevMin[0] = Line[0];
	prevMin[1] = Line[1];
	prevMin[2] = Line[2];

	prevMax[0] = Line[0];
	prevMax[1] = Line[1];
	prevMax[2] = Line[2];

	for (int i = 1; i < N; i++)
	{
		cin >> Line[0] >> Line[1] >> Line[2];

		int currentMin[3] = { INT_MAX,INT_MAX ,INT_MAX };
		int currentMax[3] = { 0, 0 ,0 };

		for (int x = 0; x < 3; x++)
		{
			for (int j = 0; j < 3; j++)
			{
				int nx = x + dx[j];

				if (nx < 0 || nx >= 3) continue;

				currentMin[x] = min(prevMin[nx] + Line[x], currentMin[x]);
				currentMax[x] = max(prevMax[nx] + Line[x], currentMax[x]);
			}
		}

		for (int j = 0; j < 3; j++)
		{
			prevMax[j] = currentMax[j];
			prevMin[j] = currentMin[j];
		}
	}
	 
	cout << *max_element(begin(prevMax), end(prevMax)) << " " << *min_element(begin(prevMin), end(prevMin));
}