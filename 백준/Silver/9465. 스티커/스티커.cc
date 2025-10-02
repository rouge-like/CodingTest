#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int T;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        int n;
        int ans = 0;
        cin >> n;

        vector<vector<int>> s(2, vector<int>(n, 0));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> s[i][j];
            }
        }

        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = s[0][0];
        dp[0][2] = s[1][0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + s[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + s[1][i];
        }

        cout << max({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }) << "\n";
    }

    return 0;
}

