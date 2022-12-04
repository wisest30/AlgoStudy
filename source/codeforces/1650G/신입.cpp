#include <stdio.h>
#include <string.h>
#include <queue>
 
using namespace std;
 
struct mov
{
	int curNode;
	int curLen;
	bool isSecond;
};
 
constexpr size_t MAXN = 2'00000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
 
int dist[MAXN][2];
int cnt[MAXN][2];
vector<int> adj[MAXN];
 
int N, M;
int S, E;
 
int main()
{
	int T;
 
	scanf("%d", &T);
 
	while (T--)
	{
		scanf("%d %d", &N, &M);
		scanf("%d %d", &S, &E);
 
		for (int i = 1; i <= N; i++)
		{
			adj[i].clear();
			memset(dist[i], 0x3f, sizeof(dist[i]));
			memset(cnt[i], 0, sizeof(cnt[i]));
		}
 
		for (int i = 0; i < M; i++)
		{
			int	u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
 
		queue<mov> q;
		dist[S][0] = 0;
		cnt[S][0] = 1;
		cnt[S][1] = 0;
		q.push({ S, 0, false });
 
		while (!q.empty())
		{
			mov cur = q.front();
			q.pop();
 
			for (int nxt : adj[cur.curNode])
			{
					if (cur.curLen + 1 < dist[nxt][0])
					{
						dist[nxt][0] = cur.curLen + 1;
						cnt[nxt][0] = cnt[cur.curNode][cur.isSecond];
						q.push({ nxt, cur.curLen + 1, false });
					}
					else if (cur.curLen + 1 == dist[nxt][0])
					{
						cnt[nxt][0] = (cnt[nxt][0] + cnt[cur.curNode][cur.isSecond]) % MOD;
					}
					else if (cur.curLen + 1 < dist[nxt][1] && cur.curLen + 1 == dist[nxt][0] + 1)
					{
						dist[nxt][1] = cur.curLen + 1;
						cnt[nxt][1] = cnt[cur.curNode][cur.isSecond];
						q.push({ nxt, cur.curLen + 1, true });
					}
					else if (cur.curLen + 1 == dist[nxt][1])
					{
						cnt[nxt][1] = (cnt[nxt][1] + cnt[cur.curNode][cur.isSecond]) % MOD;
					}
			}
		}
 
		printf("%d\n", (cnt[E][0] + cnt[E][1]) % MOD);
	}
 
	return 0;
}
