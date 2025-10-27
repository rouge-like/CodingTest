#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int T;
vector<long long> dp(101,0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> T;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for (int i = 5; i < 101; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    
    while(T--)
    {
        int n;
        cin >> n;

        cout << dp[n - 1] << "\n";
    }
}