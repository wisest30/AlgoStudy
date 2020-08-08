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
 
struct Node
{
	ll total;
	ll badTotal;
};
 
int n;
 
Node node[100000 + 5];
ll citizen[100000 + 5];
ll score[100000 + 5];
 
vector<int> adj[100000 + 5];
 
bool dfs(int here, int parent)
{
	for (int next : adj[here])
	{
		if (next == parent) continue;
		
		bool res = dfs(next, here);
		if (!res) return false;
 
		node[here].total += node[next].total;
		node[here].badTotal += node[next].badTotal;
	}
 
	ll doubleGood = node[here].total + score[here];
	ll doubleBad = node[here].total - score[here];
 
	if (doubleGood < 0 || doubleBad < 0 || doubleGood % 2 || doubleBad % 2) return false;
 
	ll minimumBadFlow = doubleBad / 2 - citizen[here];
 
	if (minimumBadFlow > node[here].badTotal) return false;
 
	node[here].badTotal = doubleBad / 2;
	
	return true;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	scanf("%d", &t);
 
	while (t--)
	{
		int m;
 
		scanf("%d %d", &n, &m);
 
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &citizen[i]);
			node[i].total = citizen[i];
		}
		for (int i = 1; i <= n; i++) scanf("%lld", &score[i]);
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
 
			scanf("%d %d", &a, &b);
 
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
 
		
 
		if (dfs(1, 0)) printf("YES\n");
		else printf("NO\n");
 
		for (int i = 1; i <= n; i++)
		{
			adj[i].clear();
			node[i].badTotal = 0;
		}
	}
 
	return 0;
}
