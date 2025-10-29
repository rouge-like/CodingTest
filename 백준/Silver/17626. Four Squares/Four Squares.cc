#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int n;
vector<int> dp(50001,INT_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j * j <= i; ++j)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n] << '\n';
}