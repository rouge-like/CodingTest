#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long m;
    cin >> n >> m;

    vector<int> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    int l = 0;
    int r = *max_element(g.begin(), g.end());
    int result = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        long long sum = 0;

        // mid보다 큰 나무들만 잘린 길이 더하기
        for (int h : g) {
            if (h > mid) sum += (h - mid);
        }

        if (sum >= m) {          // 충분히 잘렸으니 더 높여본다
            result = mid;
            l = mid + 1;
        } else {                 // 모자라니 낮춘다
            r = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}