#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

long long A, B, C;
long long mod_pow(long long a, long long b, long long c)
{
	if (b == 0) return 1;
	long long half = mod_pow(a, b / 2, c);

	half = (half * half) % c;

	if (b % 2 == 0) return half;
	else return (half * a) % c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	cout << mod_pow(A, B, C);
		
}