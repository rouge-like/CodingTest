#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool finished = false;
vector<int> path;

void dfs(vector<vector<string>>& g, vector<bool>& used, vector<int>& p, int c)
{
    if (p.size() == g.size()) {
        if (path.empty()) {
            path = p;
            finished = true;
        }
        return;
    }

    string next = g[c][1];

    for (int i = 0; i < g.size(); i++) {
        if (!used[i] && g[i][0] == next) {
            used[i] = true;
            p.push_back(i);
            dfs(g, used, p, i);
            if (finished) return;
            used[i] = false;
            p.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    answer.push_back("ICN");

    int n = tickets.size();

    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < n; i++)
    {
        if (tickets[i][0] == "ICN")
        {
            vector<bool> used(n, false);
            vector<int> p;

            used[i] = true;
            p.push_back(i);
            dfs(tickets, used, p, i);
            if (finished) break;
        }
    }

    for (int i = 0; i < path.size(); i++)
    {
        answer.push_back(tickets[path[i]][1]);
    }

    return answer;
}