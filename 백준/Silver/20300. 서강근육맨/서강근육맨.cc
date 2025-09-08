#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    long long ans = 0;
    int l = 0, r = N - 1;
    if (N % 2 == 1) {
        ans = max(ans, a[r]);
        --r;                 
    }

    while (l < r) 
    {
        ans = max(ans, a[l] + a[r]);
        ++l; --r;
    }

    cout << ans << '\n';
    return 0;
}