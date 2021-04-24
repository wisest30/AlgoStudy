#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

class SimpleSegTree {
private :
    int n;
    vector<long long> T;

public :
    SimpleSegTree() = delete;
    SimpleSegTree(int n)
    : n(n), T(4 * n + 20)
    {/* init code */}

private :
    void put(int i, int l, int r, long long val, int idx)
    {
        if (r <= idx || idx < l) return;
        if (l+1 == r)
        {
            T[i] = val;
            return;
        }
        int m = (l + r) / 2;
        put(i * 2 + 1, l, m, val, idx);
        put(i * 2 + 2, m, r, val, idx);
        T[i] = __gcd(T[i * 2 + 1], T[i * 2 + 2]);
    }
    long long get(int i, int l, int r, int L, int R)
    {
        if(L <= l && r <= R)
            return T[i];

        int m = (l + r) / 2;
        long long ret = 0;
        if(L < m)
            ret = __gcd(ret, get(i * 2 + 1, l, m, L, R));
        if(R > m)
            ret = __gcd(ret, get(i * 2 + 2, m, r, L, R));

        return ret;
    }

public :
    void put(long long val, int idx) { put(0, 0, n, val, idx); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

struct Query {
    int id, C, W;
    ll answer = 0;
};

struct Edge {
    int L;
    ll A;
    int to;
};

struct Node {
    vector<Edge> edges;
    vector<Query> queries;
};

constexpr int MAX_L = 2e5 + 1;
vector<Node> nodes;
SimpleSegTree st(MAX_L);
void dfs(int cur, int prev) {
    for(auto& query : nodes[cur].queries)
        query.answer = st.get(0, query.W + 1);

    for(auto& e : nodes[cur].edges) {
        if(e.to == prev) continue;
        st.put(e.A, e.L);
        dfs(e.to, cur);
        st.put(0, e.L);
    }
}

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    nodes = vector<Node>(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v, l;
        ll a;
        cin >> u >> v >> l >> a;
        u--, v--;
        nodes[u].edges.push_back({l, a, v});
        nodes[v].edges.push_back({l, a, u});
    }

    for(auto i = 0; i < q; ++i) {
        Query query;
        cin >> query.C >> query.W;
        query.C--;
        query.id = i;

        nodes[query.C].queries.push_back(query);
    }

    dfs(0, -1);

    vector<ll> ret(q);
    for(auto& node : nodes)
        for(auto& query : node.queries)
            ret[query.id] = query.answer;

    for(auto x : ret)
        cout << x << " ";
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
