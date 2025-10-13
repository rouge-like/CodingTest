#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

int T;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        string cmd;
        cin >> cmd;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> dq;
        string num;

        for (char c : arr)
        {
            if (isdigit(c)) num += c;
            else if (c == ',' || c == ']')
            {
                if (!num.empty())
                {
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }

        bool rev = false;
        bool err = false;

        for (char c : cmd)
        {
            if (c == 'R') rev = !rev;
            else if (c == 'D')
            {
                if (dq.empty())
                {
                    err = true;
                    break;
                }
                if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (err) cout << "error\n";
        else
        {
            cout << "[";
            if (rev) reverse(dq.begin(), dq.end());

            for (int i = 0; i < dq.size(); i++)
            {
                cout << dq[i];
                if (i != dq.size() - 1)cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}

