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
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))
 
typedef long long ll;
 
using namespace std;
 
struct edge
{
	int next;
	int edgeIdx;
};
 
constexpr int MAXN = 1'00000;
constexpr ll MOD = 1'000'000'007;
 
int n;
vector<edge> adj[MAXN + 5];
vector<ll> primeFactors;
 
int edgeIdx[MAXN + 5];
ll pathCount[MAXN + 5];
 
int childrenCnt[MAXN + 5];
 
void init()
{
	for (int i = 1; i <= n; i++) adj[i].clear();
	primeFactors.clear();
}
 
void buildPathCount(int here, int parent)
{
	int &totalChildrenCnt = childrenCnt[here] = 1;
 
	for (auto& nextEdge : adj[here])
	{
		if (nextEdge.next == parent) continue;
		
		buildPathCount(nextEdge.next, here);
		
		totalChildrenCnt += childrenCnt[nextEdge.next];
		pathCount[nextEdge.edgeIdx] = 1LL * childrenCnt[nextEdge.next] * (n - childrenCnt[nextEdge.next]);
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
 
	scanf("%d", &t);
 
	while (t--)
	{
		scanf("%d", &n);
		init();
 
		for (int i = 0; i < n-1; i++)
		{
			edgeIdx[i] = i;
 
			int u, v;
 
			scanf("%d %d", &u, &v);
			adj[u].push_back({ v, i});
			adj[v].push_back({ u, i});
		}
 
		int m;
		scanf("%d", &m);
 
		for (int i = 0; i < m; i++)
		{
			ll prime;
			
			scanf("%lld", &prime);
			primeFactors.push_back(prime);
		}
 
		for (int i = m; i < n - 1; i++) primeFactors.push_back(1);
		sort(primeFactors.begin(), primeFactors.end());
 
		while ((int)primeFactors.size() > n - 1)
		{
			ll temp = primeFactors.back();
			primeFactors.pop_back();
			primeFactors.back() = (1LL * primeFactors.back() * temp) % MOD;
		}
 
		buildPathCount(1, 0);
		sort(edgeIdx, edgeIdx + n - 1,
			[&](const int& a, const int& b)
		{
			return pathCount[a] < pathCount[b];
		});
 
		ll ans = 0LL;
 
		for (int i = 0; i < n - 1; i++)
		{
			pathCount[edgeIdx[i]] %= MOD;
			ans = (ans + 1LL * pathCount[edgeIdx[i]] * primeFactors[i]) % MOD;
		}
 
		printf("%lld\n", ans);
	}
 
	return 0;
}
