#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int N, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while (T--)
    {
        cin >> N;
        vector<pair<int, int>> score;
        score.resize(N);
        map<pair<int, int>, int> cnt;

        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            score[i] = { a,b };
        }

        sort(score.begin(), score.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
        int sec = score[0].second;
        cnt[score[0]] += 1;
        for (int i = 1; i < N; i++)
        {
            if (score[i].second < sec)
            {
                sec = score[i].second;
                cnt[score[i]] += 1;
            }
        }

        sort(score.begin(), score.end(), [](pair<int, int> a, pair<int, int> b) {return a.second < b.second; });
        int first = score[0].first;
        cnt[score[0]] += 1;
        for (int i = 1; i < N; i++)
        {
            if (score[i].first < first)
            {
                first = score[i].first;
                cnt[score[i]] += 1;
            }
        }
        int result = 0;
        for (auto m : cnt)
        {
            if (m.second == 2) result++;
        }

        cout << result << "\n";
    }

    return 0;
}