#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	queue<pair<int, int>> q; // {현재 값, 연산 횟수}
	vector<bool> visited(n + 1, false);

	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (x == 1)
		{
			cout << cnt;
			break;
		}
		if (x % 3 == 0 && !visited[x / 3]) {
			visited[x / 3] = true;
			q.push({ x / 3, cnt + 1 });
		}

		if (x % 2 == 0 && !visited[x / 2]) {
			visited[x / 2] = true;
			q.push({ x / 2, cnt + 1 });
		}

		if (!visited[x - 1]) {
			visited[x - 1] = true;
			q.push({ x - 1, cnt + 1 });
		}
	}
}