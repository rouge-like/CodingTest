#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int S = 0;
    for (int i = 0; i < N; i++)
    {
        S += A[i] * B[N - 1 - i];
    }

    cout << S;
    return 0;
}