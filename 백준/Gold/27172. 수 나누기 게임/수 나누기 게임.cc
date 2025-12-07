#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    int maxV = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        maxV = max(maxV, a[i]);
    }

    vector<int> cnt(maxV + 1, 0);
    vector<int> score(maxV + 1, 0);

    for (int x : a) cnt[x] = 1;

    for (int v = 1; v <= maxV; v++) {
        if (cnt[v] == 0) continue;

        for (int m = v * 2; m <= maxV; m += v) {
            if (cnt[m]) {
                score[v] += 1;
                score[m] -= 1;
            }
        }
    }

    for (int x : a) {
        cout << score[x] << " ";
    }

    return 0;
}