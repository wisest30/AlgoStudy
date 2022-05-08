#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

int N;
vector<string> str;

vector<int> ed[26];
vector<int> st[26];
vector<int> stAndEd[26];

vector<int> adj[100 + 5];
int indegree[100 + 5];

bool chk(string& temp)
{
	vector<int> idxes[26]{};

	for (int i = 0; i < temp.size(); i++)
	{
		char ch = temp[i];
		idxes[ch - 'A'].push_back(i);
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j + 1 < idxes[i].size(); j++)
		{
			if (idxes[i][j + 1] - idxes[i][j] != 1) return false;
		}
	}

	return true;
}

void solve()
{
	int total = 0;
	str.clear();

	for (int i = 0; i < 26; i++)
	{
		ed[i].clear();
		st[i].clear();
		stAndEd[i].clear();
	}

	cin >> N;

	for (int i = 0; i < N; i++) adj[i].clear();
	memset(indegree, 0, sizeof(indegree));

	bool impossible = false;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		str.push_back(temp);
		if (!chk(temp)) impossible = true;

		if (temp[0] == temp.back()) stAndEd[temp[0] - 'A'].push_back(i);
		else
		{
			st[temp[0] - 'A'].push_back(i);
			ed[temp.back() - 'A'].push_back(i);
		}

		total += temp.size();
	}

	for (int i = 0; i < 26; i++)
	{
		if (ed[i].size() > 1)
		{
			impossible = true;
			break;
		}
		else if (st[i].size() > 1)
		{
			impossible = true;
			break;
		}

		if (!ed[i].empty())
		{
			if (!stAndEd[i].empty())
			{
				adj[ed[i][0]].push_back(stAndEd[i][0]);
				indegree[stAndEd[i][0]]++;

				for (int j = 1; j < stAndEd[i].size(); j++)
				{
					adj[stAndEd[i][j - 1]].push_back(stAndEd[i][j]);
					indegree[stAndEd[i][j]]++;
				}
				
				if (!st[i].empty())
				{
					adj[stAndEd[i].back()].push_back(st[i][0]);
					indegree[st[i][0]]++;
				}
			}
			else if(!st[i].empty())
			{
				adj[ed[i][0]].push_back(st[i][0]);
				indegree[st[i][0]]++;
			}
		}
		else
		{
			if (!stAndEd[i].empty())
			{
				for (int j = 1; j < stAndEd[i].size(); j++)
				{
					adj[stAndEd[i][j - 1]].push_back(stAndEd[i][j]);
					indegree[stAndEd[i][j]]++;
				}

				if (!st[i].empty())
				{
					adj[stAndEd[i].back()].push_back(st[i][0]);
					indegree[st[i][0]]++;
				}
			}
		}
	}

	string ans;
	deque<int> dq;

	for (int i = 0; i < N; i++)
	{
		if (indegree[i] == 0) dq.push_back(i);
	}

	while (!dq.empty())
	{
		int cur = dq.front();
		dq.pop_front();

		ans += str[cur];

		for (auto& nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0) dq.push_front(nxt);
		}
	}

	if (!chk(ans)) impossible = true;
	if (ans.size() != total) impossible = true;

	if (impossible)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	else cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
