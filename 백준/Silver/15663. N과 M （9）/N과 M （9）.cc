#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;
vector<int> a, pick;
vector<int> used;

void dfs(int depth) 
{
    if (depth == m) {
        for (int i = 0; i < m; ++i) 
        {
            if (i) cout << ' ';
            cout << pick[i];
        }
        cout << '\n';
        return;
    }

    int last = -1;               
    for (int i = 0; i < n; i++) 
    {
        if (used[i]) continue;
        if (a[i] == last) continue;

        used[i] = 1;
        pick.push_back(a[i]);
        dfs(depth + 1);
        pick.pop_back();
        used[i] = 0;

        last = a[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    used.assign(n, 0);
    pick.reserve(m);
    dfs(0);
}