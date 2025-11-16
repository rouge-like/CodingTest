#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<vector<int>> graph;
vector<int> subtree;
vector<bool> visited;

int dfs(int node) 
{
    visited[node] = true;
    int cnt = 1;
    for (int next : graph[node]) 
    {
        if (!visited[next]) 
        {
            cnt += dfs(next);
        }
    }
    subtree[node] = cnt;
    return cnt;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> Q;

    graph.resize(N + 1);
    subtree.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(R);

    while (Q--) 
    {
        int u;
        cin >> u;
        cout << subtree[u] << "\n";
    }

    return 0;
}
