#include <bits/stdc++.h>
using namespace std;

vector<int> parent, ufRank;

int find(int x) 
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) 
{
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (ufRank[a] < ufRank[b]) swap(a, b);
    parent[b] = a;
    if (ufRank[a] == ufRank[b]) ufRank[a]++;
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    parent.resize(n);
    ufRank.resize(n, 0);

    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 1; i <= m; i++) 
    {
        int a, b;
        cin >> a >> b;

        if (!unite(a, b)) 
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";
    return 0;
}
