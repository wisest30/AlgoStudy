typedef long long ll;

struct Edge
{
	int v;
	ll cost;
};

bool operator<(const Edge& a, const Edge& b)
{
	return a.cost > b.cost;
}

class Solution {
public:
	void dijkstra(vector<vector<Edge>>& adj, vector<ll>& dist, int from)
	{
		priority_queue<Edge> pq;
		dist[from] = 0;
		pq.push({ from, 0 });

		while (!pq.empty())
		{
			Edge cur = pq.top();
			pq.pop();

			if (cur.cost > dist[cur.v]) continue;

			for (auto& next : adj[cur.v])
			{
				if (next.cost + cur.cost < dist[next.v])
				{
					dist[next.v] = next.cost + cur.cost;
					pq.push({ next.v, dist[next.v] });
				}
			}
		}
	}

	long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
		vector<vector<Edge>> reverseAdj(1'00000 + 5);
		vector<vector<Edge>> adj(1'00000 + 5);

		vector<ll> fromDest(1'00000 + 5, LLONG_MAX);
		vector<ll> fromSrc1(1'00000 + 5, LLONG_MAX);
		vector<ll> fromSrc2(1'00000 + 5, LLONG_MAX);

		for (auto& edge : edges)
		{
			adj[edge[0]].push_back({ edge[1], edge[2] });
			reverseAdj[edge[1]].push_back({ edge[0], edge[2] });
		}

		dijkstra(reverseAdj, fromDest, dest);
		dijkstra(adj, fromSrc1, src1);
		dijkstra(adj, fromSrc2, src2);

		ll ans = LLONG_MAX;

		if (fromSrc1[dest] != LLONG_MAX && fromSrc2[dest] != LLONG_MAX) ans = fromSrc1[dest] + fromSrc2[dest];

		for (int mid = 0; mid < n; mid++)
		{
			if (fromSrc1[mid] == LLONG_MAX) continue;
			if (fromSrc2[mid] == LLONG_MAX) continue;
			if (fromDest[mid] == LLONG_MAX) continue;
			ans = min(ans, fromSrc1[mid] + fromSrc2[mid] + fromDest[mid]);
		}
        
        if(ans == LLONG_MAX) return -1;
        
		return ans;
	}
};
