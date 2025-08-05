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
    vector<long long> banned_nums;
    for (const string& s : bans) {
        banned_nums.push_back(spellToInt(s));
    }
    sort(banned_nums.begin(), banned_nums.end());

    long long low = 0;
    // n에 bans.size()를 더한 값을 초기 상한으로 설정하면 대부분의 경우 충분합니다.
    long long high = n + bans.size(); 
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // mid보다 작거나 같은 금지된 숫자의 개수를 찾습니다.
        // upper_bound는 mid보다 큰 첫 번째 원소의 반복자를 반환합니다.
        // 따라서 시작점과의 거리가 mid보다 작거나 같은 원소의 개수가 됩니다.
        long long banned_count = upper_bound(banned_nums.begin(), banned_nums.end(), mid) - banned_nums.begin();
        
        // mid까지의 유효한 주문 개수
        long long valid_count = (mid + 1) - banned_count;

        if (valid_count >= n) {
            // mid가 가능한 답이므로 저장하고, 더 작은 답이 있는지 왼쪽을 탐색합니다.
            ans = mid;
            high = mid - 1;
        } else {
            // 유효한 주문이 n개보다 적으므로, 더 큰 인덱스를 찾아야 합니다.
            low = mid + 1;
        }
    }

    // 찾은 ans가 금지된 주문일 경우, 금지되지 않은 다음 주문을 찾습니다.
    while (binary_search(banned_nums.begin(), banned_nums.end(), ans)) 
	{
        ans++;
    }

    return intToSpell(ans);
}