#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    while (N--)
    {
        int a;
        cin >> a;

        if (a == 0)
        {
            if (pq.size() == 0)
            {
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(a);
    }


    return 0;
}