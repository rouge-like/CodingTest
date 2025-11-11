#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int C, N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> C >> N;
    
    vector<pair<int, int>> costs(N);


    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        costs[i] = { a,b };
    }

    const int MAX_COST = 100000;
    vector<int> dp(MAX_COST + 1);

    for (int i = 0; i < N; i++) 
    {
        int cost = costs[i].first;
        int people = costs[i].second;

        for (int j = cost; j <= MAX_COST; j++) 
        {
            dp[j] = max(dp[j], dp[j - cost] + people);
        }
    }

    int ans = MAX_COST;
    for (int i = 0; i <= MAX_COST; i++) 
    {
        if (dp[i] >= C) 
        {
            ans = i;
            break;
        }
    }

    cout << ans;
}