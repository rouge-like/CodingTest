#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int X1, Y1, X2, Y2;
int bt[1025][1025];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            sum += a;

            bt[i][j] = sum + bt[i-1][j];
        }
    }
    while (M--)
    {
        cin >> X1 >> Y1 >> X2 >> Y2;

        int A = bt[X2][Y2];
        int B = bt[X2][Y1 - 1];
        int C = bt[X1 - 1][Y2];
        int D = bt[X1 - 1][Y1 - 1];

        cout << A - B - C + D << "\n";

    }

    return 0;
}