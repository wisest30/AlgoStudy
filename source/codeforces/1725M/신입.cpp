#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <string.h>
 
#include <vector>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
struct Element
{
	int node;
	ll dist;
	bool usedReversedEdge;
};
 
bool operator<(const Element& a, const Element& b)
{
	return a.dist > b.dist;
}
 
struct Edge
{
	int node;
	ll dist;
};
 
int N;
 
vector<Edge> edges[1'00000 + 5], reversedEdges[1'00000 + 5];
ll dist[1'00000 + 5][2];
 
int main()
{
	memset(dist, 0x7f, sizeof(dist));
 
	int M;
 
	scanf("%d %d", &N, &M);
 
	for (int i = 0; i < M; i++)
	{
		int u, v;
		ll dist;
 
		scanf("%d %d %lld", &u, &v, &dist);
		edges[u].push_back({ v, dist });
		reversedEdges[v].push_back({ u, dist });
	}
 
	priority_queue<Element> pq;
	pq.push({ 1, 0, false });
 
	dist[1][0] = 0LL;
	dist[1][1] = 0LL;
 
	while (!pq.empty())
	{
		Element cur = pq.top();
		pq.pop();
 
		if (cur.dist > dist[cur.node][cur.usedReversedEdge]) continue;
 
		if (!cur.usedReversedEdge)
		{
			for (const auto& edge : edges[cur.node])
			{
				if (cur.dist + edge.dist < dist[edge.node][0])
				{
					dist[edge.node][0] = cur.dist + edge.dist;
					pq.push({ edge.node, dist[edge.node][0], false });
				}
			}
		}
		for (const auto& edge : reversedEdges[cur.node])
		{
			if (cur.dist + edge.dist < dist[edge.node][1])
			{
				dist[edge.node][1] = cur.dist + edge.dist;
				pq.push({ edge.node, dist[edge.node][1], true });
			}
		}
	}
 
	for (int i = 2; i <= N; i++)
	{
		ll ans = min(dist[i][0], dist[i][1]);
 
		if (ans == 0x7f7f7f7f7f7f7f7f) ans = -1;
		printf("%lld ", ans);
	}
	printf("\n");
 
	return 0;
}
