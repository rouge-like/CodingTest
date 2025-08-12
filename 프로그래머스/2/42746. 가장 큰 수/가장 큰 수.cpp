#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare 
{
	bool operator()(string a, string b)
	{
		return a + b > b + a;
	}
};

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> strings;
	for(auto& i : numbers)
		strings.push_back(to_string(i));
	
	sort(strings.begin(), strings.end(), Compare());
    
    if (strings[0] == "0") return "0";
    
	for (auto& i : strings)
		answer += i;

	return answer;
}