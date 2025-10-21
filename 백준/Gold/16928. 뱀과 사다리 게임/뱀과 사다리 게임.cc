#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int N, M;
vector<int> mp(101, 0);
vector<int> visited(101, -1);

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 100; i++)
    {
        mp[i] = i;
    }
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int from, to;
        cin >> from >> to;
        mp[from] = to;
    }

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        mp[from] = to;
    }

    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty())
    {
        int c = q.front(); q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int dc = c + i;

            if (dc > 100) break;

            int next = mp[dc];

            if (visited[next] != -1) continue;

            q.push(next);
            visited[next] = visited[c] + 1;
        }
    }

    cout << visited[100];
}