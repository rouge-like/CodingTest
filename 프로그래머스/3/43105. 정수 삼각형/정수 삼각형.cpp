#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[2] = { 0,-1 };
int dy[2] = { -1,-1 };

int solution(vector<vector<int>> triangle)
{
	vector<vector<int>> dp;

	dp.push_back(triangle[0]);

	for (int i = 1; i < triangle.size(); i++)
	{
		vector<int> sums;

		for (int j = 0; j < triangle[i].size(); j++)
		{
			int max = 0;

			for (int k = 0; k < 2; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (nx >= 0 && ny >= 0 && nx < dp[ny].size() && ny < dp.size())
				{
					int tmp = dp[ny][nx] + triangle[i][j];

					if (max < tmp)
						max = tmp;
				}
			}
			sums.push_back(max);
		}
		dp.push_back(sums);
	}

	int ret = 0;
	int n = dp.size() - 1;
	for (auto it = dp[n].begin(); it != dp[n].end(); it++)
	{
		if (ret < *it)
			ret = *it;
	}

	return ret;
}