#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    int size = info.size();

    vector<vector<int>> dp(size + 1, vector<int>(m, n));
    dp[0][0] = 0;

    for (int i = 1; i <= size; i++) {
        int a = info[i - 1][0];
        int b = info[i - 1][1];
        for (int j = 0; j < m; j++) {

            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);

            if (j + b < m) 
            {
                dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
            }
        }
    }

    int ans = n;
    
    for (int j = 0; j < m; j++) 
    {
        ans = min(ans, dp[size][j]);
    }
    if (ans == n)
        return -1;
    else
        return ans;
}

