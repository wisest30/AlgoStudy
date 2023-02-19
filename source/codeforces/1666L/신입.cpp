#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

constexpr size_t MAXN = 2'00000 + 5;

bool answerFound;
bool visit[MAXN];
int prv[MAXN];

vector<int> adj[MAXN];
vector<int> firstRoute;
vector<int> secondRoute;

vector<int> visited;

int s;

void dfs(int cur, int parent, bool update)
{
	if (prv[cur] != -1 && !update)
	{
		answerFound = true;
		int temp = cur;

		while (temp != -1)
		{
			firstRoute.push_back(temp);
			temp = prv[temp];
		}

		reverse(firstRoute.begin(), firstRoute.end());

		secondRoute.push_back(cur);

		return;
	}

	if (visit[cur]) return;

	visit[cur] = true;
	visited.push_back(cur);

	if(update) prv[cur] = parent;

	for (auto& nxt : adj[cur])
	{
		dfs(nxt, cur, update);

		if (answerFound)
		{
			secondRoute.push_back(cur);
			return;
		}
	}
}

int main()
{
	memset(prv, -1, sizeof(prv));
	int N, M;

	scanf("%d %d %d", &N, &M, &s);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}

	visit[s] = true;
	for (auto& nxt : adj[s])
	{
		dfs(nxt, s, false);
		
		if (!answerFound)
		{
			for (int num : visited) visit[num] = false;
			visited.clear();
			dfs(nxt, s, true);
		}
		else break;
	}

	if (!firstRoute.empty())
	{
		printf("Possible\n%d\n", (int)firstRoute.size());
		for (int num : firstRoute) printf("%d ", num);
		
		secondRoute.push_back(s);
		reverse(secondRoute.begin(), secondRoute.end());
		printf("\n%d\n", (int)secondRoute.size());
		for (int num : secondRoute) printf("%d ", num);
		printf("\n");
	}
	else printf("Impossible\n");

	return 0;
}
