#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

constexpr int MAXN = 200000 + 5;
int n;

bool calculated[MAXN];
ll input[MAXN];
ll mx[MAXN];
int indegree[MAXN];

vector<int> adj[MAXN];
vector<int> topologicalAdj[MAXN];

ll getMx(int here)
{
	if (calculated[here]) return mx[here];

	calculated[here] = true;
	ll& ret = mx[here] = input[here];

	for (auto next : adj[here])
	{
		ll res = getMx(next);
		if (res >= 0)
		{
			ret += res;
			topologicalAdj[next].push_back(here);
			indegree[here]++;
		}
		else
		{
			topologicalAdj[here].push_back(next);
			indegree[next]++;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%lld", &input[i]);
	for (int i = 1; i <= n; i++)
	{
		int target;
		scanf("%d", &target);
    		if(target != -1) adj[target].push_back(i);
	}

	ll ans = 0LL;
	for (int i = 1; i <= n; i++) ans += getMx(i);
	printf("%lld\n", ans);

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		printf("%d ", cur);
		for (auto next : topologicalAdj[cur])
		{
			if (--indegree[next] == 0) q.push(next);
		}
	}

	return 0;
}
