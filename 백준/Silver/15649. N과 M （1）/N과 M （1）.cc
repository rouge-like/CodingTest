#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<int> bt;
vector<int> visited(10, 0);
void dfs()
{
    if (bt.size() != M)
    {
        for (int i = 1; i <= N; i++)
        {
            if (visited[i]) continue;
            bt.push_back(i);
            visited[i] = true;
            dfs();
        }
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            cout << bt[i] << " ";
        }
        cout << "\n";
    }
    if (!bt.empty())
    {
        visited[bt.back()] = false;
        bt.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dfs();

    return 0;
}