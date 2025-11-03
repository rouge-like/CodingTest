#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int N, M;
string S;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> N >> M;
    cin >> S;


    int cnt = 0;
    int ans = 0;
   

    for (int i = 1; i < M - 1; i++) 
    {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') 
        {
            cnt++;
            if (cnt >= N)
                ans++;

            i++;
        }
        else 
        {
            cnt = 0;
        }
    }

    cout << ans;
}