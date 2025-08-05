#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string intToSpell(long long n)
{
	int size = 1;
	long long count = 0;

	while (true)
	{
		long long add = 1;
		for (int i = 0; i < size; i++) 
			add *= 26;

		if (count + add > n) break;
		count += add;
		size++;
	}

	n -= count;
	string spell(size, 'a');

	for (int i = size - 1; i >= 0; i--)
	{
		spell[i] = 'a' + (n % 26);
		n /= 26;
	}

	return spell;
}

long long spellToInt(string s)
{
	long long sum = 0;
	long long base = 1;
	for (int i = 1; i < s.size(); i++)
	{
		base *= 26;
		sum += base;
	}

	base = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		sum += base * (s[i] - 'a');
		base *= 26;
	}
	return sum;
}


string solution(long long n, vector<string> bans) {
    vector<long long> banList;
    for (const string& s : bans) {
        banList.push_back(spellToInt(s));
    }
    sort(banList.begin(), banList.end());

    long long left = 0, right = 1e18, answer = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;

        // 금지어 중 mid 이하인 개수
        long long bannedCount = upper_bound(banList.begin(), banList.end(), mid) - banList.begin();
        long long validCount = mid - bannedCount + 1;

        if (validCount >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return intToSpell(answer);
}