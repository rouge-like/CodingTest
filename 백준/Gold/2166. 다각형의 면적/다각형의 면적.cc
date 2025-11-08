#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long double, long double>> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;

    long double sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        sum1 += pos[i].first * pos[j].second;
        sum2 += pos[i].second * pos[j].first;
    }

    cout << fixed;
    cout.precision(1);
    cout << fabsl(sum1 - sum2) / 2.0;

    return 0;
}
