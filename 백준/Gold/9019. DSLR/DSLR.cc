#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int T;

string bfs(int start, int end)
{
    vector<bool> visited(10001, false);
    vector<int> parent(10000, -1);
    vector<char> how(10000, 0);

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int current = q.front(); q.pop();
        if (current == end) break;

        int next[4];

        next[0] = current * 2 % 10000;
        next[1] = current == 0 ? 9999 : current - 1;
        next[2] = current / 1000 + (current % 1000) * 10;
        next[3] = current / 10 + (current % 10) * 1000;

        char cmd[4] = {'D', 'S', 'L', 'R'};
        for (int i = 0; i < 4; i++)
        {
            if (visited[next[i]]) continue;

            visited[next[i]] = true;
            parent[next[i]] = current;
            how[next[i]] = cmd[i];
            q.push(next[i]);
        }
    }

    string ans;
    for (int i = end; i != start; i = parent[i])
    {
        ans.push_back(how[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        int a, b;
        cin >> a >> b;

        cout << bfs(a, b) << "\n";
    }
}