#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int N, r, c;
int cnt;
bool bFound = false;
void ZZ(int y, int x, int size)
{
	if (size == 1)
	{
		if (y == r && x == c)
		{
			cout << cnt;
			bFound = true;
			return;
		}
		cnt++;
	}
	else
	{
		int csize = size / 2;
		int ny, nx;
		int tmp = 0;
		if (r < y + csize)
		{
			ny = y;
			if (c < x + csize)
			{
				tmp = 0;
				nx = x;
			}
			else
			{
				tmp = 1;
				nx = x + csize;
			}
		}
		else
		{
			ny = y + csize;
			if (c < x + csize)
			{
				tmp = 2;
				nx = x;
			}
			else
			{
				tmp = 3;
				nx = x + csize;
			}
		}
		cnt += csize * csize * tmp;

		ZZ(ny, nx, csize);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	int size = pow(2, N) * 2;
	ZZ(0, 0, size);
}