#include <bits/stdc++.h>
using namespace std; using ii = pair<int,int>; using ll = long long; using vi = vector<int>;
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define per(i,a,b) for (auto i = (b); i >= (a); --i)
#define all(x) begin(x), end(x)
#define siz(x) int32_t((x).size())
#define Mup(x,y) (x = max(x,y))
#define mup(x,y) (x = min(x,y))
#define fi first
#define se second
#define pb push_back
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define int long long

const int N = 1e5+3, INF = 1e18;
int n, a[N], p[N];

struct seg {
    struct node {
        int m, M, ans;
        node(): m(INF), M(-INF), ans(-INF){}
        node(int v1, int v2): m(v1), M(v1), ans(v2){}
        node operator + (const node &rhs) const {
            node r{};
            r.m = min(m, rhs.m);
            r.M = max(M, rhs.M);
            r.ans = max({ans, rhs.ans, rhs.M - m});
            return r;
        }
    };
    node t[2*N];
    seg(){
        fill(t,t+2*N,node{});
    }
    void build() {
        per(k,1,N-1){
            t[k]=t[2*k]+t[2*k+1];
        }
    }
    node query(int l, int r) {
        assert(l<=r);
        node L{}, R{};
        for (l+=N,r+=N;l<=r;++l/=2,--r/=2){
            if(l&1) L=L+t[l];
            if(~r&1) R=t[r]+R;
        }
        return L+R;
    }
} ds;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    ds.t[N]=seg::node(0,0);
    rep(i,1,n) {
        cin >> a[i];
        p[i] = p[i-1]+a[i];
        ds.t[N+i] = seg::node(p[i],a[i]);
    }
    ds.build();
    
    int t; cin >> t; while (t--)
    {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        s1--, s2--;
        
        if (s2 < e1) { // 교차 x
            cout << ds.query(e1,e2).M - ds.query(s1,s2).m << '\n';
        } else {
            int res = -INF;
            Mup(res, ds.query(e1,e2).M - ds.query(s1,e1-1).m);
            Mup(res, ds.query(s2+1,e2).M - ds.query(s1,s2).m);
            Mup(res, ds.query(e1,s2).ans);
            assert(res > -INF);
            cout << res << '\n';
        }
    }
}
