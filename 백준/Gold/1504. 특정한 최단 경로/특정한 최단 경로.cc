#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n, e;
vector<vector<pair<int, int>>> edges(801);
int start, goal;

vector<long long> dijkstra(int v)
{
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[v] = 0;
    pq.push({ 0, v });

    while (pq.size())
    {
        long long cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < cost) continue;

        for (auto& x : edges[current])
        {
            int next = x.first;
            long long w = x.second;

            if (dist[next] > cost + w)
            {
                dist[next] = cost + w;
                pq.push({ dist[next], next });
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({ v,w });
        edges[v].push_back({ u,w });
    }
    cin >> start >> goal;

    auto d1 = dijkstra(1);
    auto ds = dijkstra(start);
    auto dg = dijkstra(goal);

    bool ok1 = (d1[start] < LLONG_MAX && ds[goal] < LLONG_MAX && dg[n] < LLONG_MAX);
    bool ok2 = (d1[goal] < LLONG_MAX && dg[start] < LLONG_MAX && ds[n] < LLONG_MAX);

    long long result = LLONG_MAX;

    if (ok1) result = min(result, d1[start] + ds[goal] + dg[n]);
    if (ok2) result = min(result, d1[goal] + dg[start] + ds[n]);

    if (result >= LLONG_MAX) cout << -1;
    else cout << result;
 
    return 0;
}
