#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int N, S;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> N >> S;
    vector<long long> v(N + 1);
    int tmp = 0;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        tmp += a;
        v[i] = tmp;
    }

    // 0 5 6 9 14 24 31 35
    int l = 0;
    int r = 1;
    int ans = INT_MAX;
    while (l <= r && r <= N)
    {
        int sum = v[r] - v[l];

        if (sum >= S)
        {
            ans = min(ans, r - l);
            l++;
        }
        else
        {
            r++;
        }
    }

    if (ans == INT_MAX) cout << 0;
    else cout << ans;
}