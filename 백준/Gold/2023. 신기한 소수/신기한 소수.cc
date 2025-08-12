#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int Nums[4] = {1,3,7,9};
int FirstNums[4] = { 2,3,5,7 };
vector<int> Ids;
vector<int> rets;

bool isPrime(int n)
{
	if (n <= 1)
		return false;

	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false;

	for (int i = 3; i < sqrt(n); i += 2)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int GetSum()
{
	if (Ids.size() == 0)
		return 0;

	if (Ids.size() == 1)
		return FirstNums[Ids[0]];

	int sum = Nums[Ids.back()];
	int i = Ids.size() - 1;

	for (int j = i - 1; j >= 0; j--)
	{
		if (j == 0)
			sum += FirstNums[Ids[j]] * pow(10, i - j);
		else
			sum += Nums[Ids[j]] * pow(10, i - j);
	}
	
	return sum;
}

void dfs()
{
	for (int i = 0; i < 4; i++)
	{
		Ids.push_back(i);

		int sum = GetSum();

		if (isPrime(sum))
		{
			if (Ids.size() == N)
			{
				rets.push_back(sum);
			}
			else
				dfs();
		}

		Ids.pop_back();
		
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dfs();

	for (auto& i : rets)
		cout << i << "\n";
}