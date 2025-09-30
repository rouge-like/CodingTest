#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> tri(501, vector<int>(501));
vector<vector<int>> dp(501, vector<int>(501));

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n; 
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j != 0)
                dp[i][j] = max( dp[i][j],dp[i - 1][j - 1] + tri[i][j] );
            dp[i][j] = max( dp[i][j], dp[i - 1][j] + tri[i][j] );
        }
    }


    cout << *max_element(dp[n - 1].begin(), dp[n-1].end());
    return 0;
}

