#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    vector<long long> sums;

    cin >> N >> M;
    arr.resize(N + 1, 0);
    sums.resize(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i + 1];

        if (i == 0)
            sums[1] = arr[1];
        else
            sums[i + 1] = arr[i + 1] + sums[i];

    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        int cnt = sums[b] - sums[a - 1];

        cout << cnt << "\n";
    }
    return 0;
}