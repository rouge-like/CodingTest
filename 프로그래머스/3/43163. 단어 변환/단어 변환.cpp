#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool canChange(string a, string b)
{
	int cnt = 0;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
			cnt++;
	}

	return cnt == (a.length() - 1);
}

int bfs(string start, string target, vector<string>& words)
{
	queue<string> q;
	vector<bool> visited(words.size(), false);
	map<string, int> dist;
	q.push(start);

	while (!q.empty())
	{
		string current = q.front();
		q.pop();

		for (int i = 0; i < words.size(); i++)
		{
			if (canChange(current, words[i]) && !visited[i])
			{
				q.push(words[i]);
				visited[i] = true;
				dist[words[i]] = dist[current] + 1;
			}
		}
	}

	return dist[target];
}

int solution(string begin, string target, vector<string> words) 
{
	int answer = 0;

	

	return bfs(begin, target, words);
}