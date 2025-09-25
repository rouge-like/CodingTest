#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };

inline long long dist2(const P& a, const P& b) {
    long long dx = 1LL * a.x - b.x;
    long long dy = 1LL * a.y - b.y;
    return dx*dx + dy*dy;
}

vector<P> a, tmp; // a: 작업 배열, tmp: 병합용 버퍼

// [l, r) 구간 처리: 반환값 = 최소 거리 제곱
long long solve(int l, int r) {
    int n = r - l;
    if (n <= 3) {
        long long d = LLONG_MAX;
        for (int i = l; i < r; ++i)
            for (int j = i + 1; j < r; ++j)
                d = min(d, dist2(a[i], a[j]));
        // 작은 구간은 y로 정렬해서 반환 (상위 병합을 위해)
        sort(a.begin() + l, a.begin() + r, [](const P& p1, const P& p2){ return p1.y < p2.y; });
        return d;
    }

    int m = (l + r) / 2;
    int midx = a[m].x; // 분할선 x

    long long d = min(solve(l, m), solve(m, r));

    // 두 하위 구간은 이미 y정렬 상태. y기준으로 병합.
    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r,
          tmp.begin(), [](const P& p1, const P& p2){ return p1.y < p2.y; });
    copy(tmp.begin(), tmp.begin() + (r - l), a.begin() + l);

    // 스트립 구성: |x - midx|^2 < d
    static vector<P> strip;
    strip.clear();
    strip.reserve(r - l);
    for (int i = l; i < r; ++i) {
        long long dx = 1LL * a[i].x - midx;
        if (dx*dx < d) strip.push_back(a[i]);
    }

    // 스트립은 y정렬 상태. 각 점은 y차이가 sqrt(d)보다 작은 최대 7개만 비교
    for (int i = 0; i < (int)strip.size(); ++i) {
        for (int j = i + 1; j < (int)strip.size(); ++j) {
            long long dy = 1LL * strip[j].y - strip[i].y;
            if (dy*dy >= d) break;
            d = min(d, dist2(strip[i], strip[j]));
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;

    // x, 그다음 y로 정렬 (중복 즉시 체크: 0)
    sort(a.begin(), a.end(), [](const P& p1, const P& p2){
        if (p1.x != p2.x) return p1.x < p2.x;
        return p1.y < p2.y;
    });
    for (int i = 1; i < n; ++i) {
        if (a[i].x == a[i-1].x && a[i].y == a[i-1].y) {
            cout << 0 << '\n';
            return 0;
        }
    }

    tmp.resize(n);
    cout << solve(0, n) << '\n';
    return 0;
}