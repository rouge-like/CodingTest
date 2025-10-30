#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;
int N, M, B;
int mp[501][501];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> N >> M >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
        }
    }
    int resultH = 0;
    int resultC = 2e9;
    for (int h = 256; h >= 0; h--)
    {
        int cost = 0;
        int block = B;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int d = h - mp[i][j];

                if (d < 0)
                {
                    cost += 2 * -d;
                    block += -d;
                }
                else if (d > 0)
                {
                    cost += 1 * d;
                    block -= d;
                }
            }
        }
        if (block < 0) continue;

        if (resultC > cost)
        {
            resultC = cost;
            resultH = h;
        }
    }
    cout << resultC << " " << resultH;
}
