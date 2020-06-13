#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <algorithm>
#include <climits>
#include <vector>
 
using namespace std;
 
struct node
{
	int cost;
	int source;
	int dest;
};
 
struct retType
{
	int zeroToOne;
	int oneToZero;
};
 
int n;
node nodes[200000 + 5];
vector<int> adj[200000 + 5];
long long ans;
 
void dfs(int cur, int parent, int minCost)
{
	if (nodes[cur].cost > minCost) nodes[cur].cost = minCost;
	for (int next : adj[cur])
	{
		if (next == parent) continue;
		dfs(next, cur, min(minCost, nodes[cur].cost));
	}
}
 
retType calcCost(int cur, int parent)
{
	int zeroToOne = 0;
	int oneToZero = 0;
 
	for (int next : adj[cur])
	{
		if (next == parent) continue;
		retType res = calcCost(next, cur);
		zeroToOne += res.zeroToOne;
		oneToZero += res.oneToZero;
	}
 
	if (nodes[cur].source != nodes[cur].dest)
	{
		if (nodes[cur].source == 0) zeroToOne++;
		else oneToZero++;
	}
 
	int pairCount = min(zeroToOne, oneToZero);
	ans += 2LL * nodes[cur].cost * pairCount;
 
	zeroToOne -= pairCount;
	oneToZero -= pairCount;
 
	return { zeroToOne, oneToZero };
}
 
int main()
{
	scanf("%d", &n);
 
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d %d", &nodes[i].cost, &nodes[i].source, &nodes[i].dest);
	}
 
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
 
	dfs(1, 0, INT_MAX);
	retType temp = calcCost(1, 0);
 
	if (temp.oneToZero || temp.zeroToOne) ans = -1;
	printf("%lld\n", ans);
 
	return 0;
}
