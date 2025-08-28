#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 987654321;

int N;
vector<int> P(1001);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	P.resize(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	sort(P.begin(), P.end());        

	long long prefix = 0, answer = 0;
	for (int x : P) 
	{
		prefix += x;               
		answer += prefix;           
	}
	cout << answer << '\n';
}