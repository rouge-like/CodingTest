#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>
#include <cmath>

using namespace std;

int N;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    vector<int> nums(N);
    int sum= 0;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    sort(nums.begin(), nums.end());

    int mean = round((double)sum / N);
    int median = nums[N / 2];

    map<int, int> mp;
    for (int num : nums) mp[num]++;

    int mx = 0;
    vector<int> modes;
    for (auto& p : mp) 
    {
        if (p.second > mx)
        {
            mx = p.second;
            modes = { p.first };
        }
        else if (p.second == mx)
        {
            modes.push_back(p.first);
        }
    }

    int mode = (modes.size() > 1) ? modes[1] : modes[0];
    int range = nums.back() - nums.front();

    cout << mean << "\n" << median << "\n" << mode << "\n" << range;
}