#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    map<int, int> S;

    for (int i = 1; i <= 20; i++)
    {
        S[i] = 0;
    }

    while (T--)
    {
        string a;
        int num;

        cin >> a;
        if (a == "empty")
        {
            for (int i = 1; i <= 20; i++)
                S[i] = 0;

            continue;
        }
        else if (a == "all")
        {
            for (int i = 1; i <= 20; i++)
                S[i] = 1;

            continue;
        }
        cin >> num;
        if (a == "add")
        {
            S[num]++;
        }
        else if (a == "remove")
        {
            S[num] = 0;
        }
        else if (a == "check")
        {
            cout << (S[num] > 0) << "\n";
        }
        else if (a == "toggle")
        {
            if (S[num] == 0)
                S[num] = 1;
            else
                S[num] = 0;
        }
        
    }
}
