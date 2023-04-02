#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

constexpr size_t MAXN = 2'00000 + 5;

vector<int> adj[MAXN];

int containsE[MAXN];
int containsMustVisit[MAXN];

int n, m;
int s, e;

set<int> mustVisit;

int ans;

int getContainsE(int cur, int prv)
{
	if (containsE[cur] != -1) return containsE[cur];

	if (cur == e) return containsE[cur] = 1;

	for (int nxt : adj[cur])
	{
		if (nxt == prv) continue;
		if (getContainsE(nxt, cur)) return containsE[cur] = 1;
	}

	return containsE[cur] = 0;
}

int getContainsMustVisit(int cur, int prv)
{
	if (containsMustVisit[cur] != -1) return containsMustVisit[cur];

	for (int nxt : adj[cur])
	{
		if (nxt == prv) continue;
		if (getContainsMustVisit(nxt, cur)) return containsMustVisit[cur] = 1;
	}

	return containsMustVisit[cur] = 0;
}

void dfs(int cur, int prv)
{
	for (int nxt : adj[cur])
	{
		if (nxt == prv) continue;

		if (getContainsE(nxt, cur)) ans++;
		else if (getContainsMustVisit(nxt, cur)) ans += 2;

		dfs(nxt, cur);
	}
}

int main()
{
	int T;

	scanf("%d", &T);
	
	while (T--)
	{
		memset(containsE, -1, sizeof(containsE));
		memset(containsMustVisit, -1, sizeof(containsMustVisit));
		ans = 0;

		int k;

		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++) adj[i].clear();

		scanf("%d %d", &s, &e);

		containsE[e] = 1;

		for (int i = 0; i < k; i++)
		{
			int input;

			scanf("%d", &input);
			mustVisit.insert(input);

			containsMustVisit[input] = 1;
		}
		
		
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(s, -1);

		printf("%d\n", ans);
	}

	return 0;
}
