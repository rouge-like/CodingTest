#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <climits>

using namespace std;

string A, B, C;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    int a, b, c;
    a = stoi(A);
    b = stoi(B);
    c = stoi(C);

    cout << a + b - c << "\n";

    A = A.append(B);

    int ab = stoi(A);

    cout << ab - c;

    return 0;
}