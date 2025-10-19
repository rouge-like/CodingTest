#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <climits>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, string> mp;

    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;

        mp[a] = b;
    }

    for (int i = 0; i < M; i++)
    {
        string b;
        cin >> b;
        cout << mp[b] << "\n";
    }
}