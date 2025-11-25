#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> cost(N + 1, vector<int>(3));
    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2]; // R G B
    }

    int answer = INF;

    for (int firstColor = 0; firstColor < 3; firstColor++) {
        vector<vector<int>> dp(N + 1, vector<int>(3, INF));

        dp[1][firstColor] = cost[1][firstColor];

        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]; // R
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]; // G
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]; // B
        }

        for (int lastColor = 0; lastColor < 3; lastColor++) {
            if (lastColor == firstColor) continue;
            answer = min(answer, dp[N][lastColor]);
        }
    }

    cout << answer << "\n";
    return 0;
}
