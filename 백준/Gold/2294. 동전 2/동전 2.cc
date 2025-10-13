#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

int n, k;
vector<int> dp(10001, 2e9);

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;

        for (int j = tmp; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - tmp] + 1);
        }
    }

    if (dp[k] == 2e9)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dp[k];
    }
    return 0;
}