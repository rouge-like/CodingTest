#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	vector<unordered_set<int>> dp(9);

	int tmp = 0;

	for (int i = 1; i <= 8; i++)
	{
		tmp = tmp * 10 + N;
		dp[i].insert(tmp);
	}
	
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j < i; j++)
		{
			for (int a : dp[j])
			{
				for (int b : dp[i - j])
				{
					dp[i].insert(a + b);
					dp[i].insert(a - b);
					dp[i].insert(a * b);
					if (b != 0) dp[i].insert(a / b);
				}
			}
		}

		if (dp[i].count(number)) return i;
	}

	return -1;
}