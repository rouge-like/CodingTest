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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;
        map<string, int> mp;

        while (n--)
        {
            string a, b;
            cin >> a >> b;
            mp[b] = mp[b] + 1;
        }

        long long result = 1;
        for (auto& p : mp) {
            result *= (p.second + 1);
        }

        cout << result - 1 << "\n";
    }
}