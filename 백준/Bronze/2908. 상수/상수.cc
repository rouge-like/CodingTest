#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	reverse(&A[0], &A[A.size()]);
	reverse(&B[0], &B[B.size()]);


	if (A < B)
	{
		cout << B;
	}
	else 
	{
		cout << A;
	}
}