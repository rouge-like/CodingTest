#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int N;
vector<vector<int>> h;
vector<vector<int>> dp;

void color(int idx)
{
    for (int color = 0; color < 3; color++)
    {
        int cost = 2e9;

        for (int i = 0; i < 3; i++)
        {
            if (i == color) continue;
            if (cost > dp[idx - 1][i])
            {
                cost = dp[idx - 1][i];
            }
        }

        dp[idx][color] = cost + h[idx][color];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    h.resize(N, vector<int>(3));
    dp.resize(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        cin >> h[i][0] >> h[i][1] >> h[i][2];
    }

    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    dp[0][2] = h[0][2];

    for (int i = 1; i < N; i++)
    {
        color(i);
    }

    int min = 2e9;

    for (int i = 0; i < 3; i++)
    {
        if (min > dp[N - 1][i])
            min = dp[N - 1][i];
    }
    cout << min;
    return 0;
}