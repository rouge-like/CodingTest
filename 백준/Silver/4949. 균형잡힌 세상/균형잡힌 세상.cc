#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A;

	while (true)
	{
		getline(cin, A);

		if (A[0] == '.' && A.size() == 1)
			break;

		stack<char> stk;
		bool flag = true;

		for (char c : A)
		{
			if (c == ')')
			{
				if (stk.size() == 0 || stk.top() != '(')
				{
					flag = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
			else if (c == ']')
			{
				if (stk.size() == 0 || stk.top() != '[')
				{
					flag = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
			else if (c == '(' || c == '[')
			{
				stk.push(c);
			}
		}

		if (flag && stk.size() == 0)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";

		}
	}
}
