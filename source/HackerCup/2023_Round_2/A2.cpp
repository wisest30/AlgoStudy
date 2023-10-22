#pragma region orange!orange!orange!orange!
// g++-12 -std=c++17 -O2 -Wall -Wno-unknown-pragmas -DLOCAL
#include <bits/stdc++.h>
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define per(i,a,b) for (auto i = (b); i >= (a); --i)
#define siz(x) int(x.size())
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define ensure(...) if (!(__VA_ARGS__)){ fprintf(stderr,"Error in %dth line.", __LINE__), exit(-1); }
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define mup(x,y) x = min(x,y)
#define Mup(x,y) x = max(x,y)
#define fi first
#define se second
using namespace std; using ll = long long; using ii = pair<int,int>; using iii = tuple<int,int,int>;  using vi = vector<int>;
constexpr int floor_log2(int x) { assert(x > 0); return 31-__builtin_clz(x) ;}
constexpr int ceil_log2(int x) { assert(x > 0); return 31-__builtin_clz(x)+bool(x&(x-1)); }
constexpr ll floor(ll p, ll q) { return p/q-((p^q) < 0 and p%q); } constexpr ll ceil(ll p, ll q) { return p/q+((p^q) > 0 and p%q); } string to_string(string s) { return '"'+s+'"'; } string to_string(bool b) { return b ? "true" : "false"; } template <typename A,typename B> string to_string(pair<A,B> p) { return "("+to_string(p.F)+", "+to_string(p.S)+")"; } template <typename A> string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) res += ", "; first = false; res += to_string(x); } res += "}"; return res; } void debug_out() { cerr << endl; } template <typename Head,typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); } void precalc(); void solution(int);
int main() {cin.tie(0)->sync_with_stdio(0); precalc(); int t; cin >> t; rep(i,1,t) solution(i);}
#pragma endregion

template <const int N>
struct disjoint_set {
    int p[N], s[N], v[N];
    disjoint_set() { iota(p,p+N,0), fill(s,s+N,1), fill(v,v+N,-1); }
    int find(int x) {
        assert(x < N);
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        // assert(a != b);
        if (a == b) return;
        if (v[a] >= 0 and v[b] >= 0 and v[a] != v[b]) v[a] = v[b] = -2;
        if (v[a] == -2 or v[b] == -2) v[a] = v[b] = -2;
        if (s[a] > s[b]) swap(a,b);
        s[b] += s[a], p[a] = b;
        if (v[b] == -1) v[b] = v[a];
    }
    int size(int x) {
        return s[find(x)];
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

const ii d4[] {{0,1},{1,0},{0,-1},{-1,0}};
const ii d8[] {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int R = 3003, C = R;
int r, c;
bool out(int x, int y) {return 1 > x or x > r or 1 > y or y > c;}
int N(int x, int y) { return (x-1)*R + (y-1);}
char s[R][C];
bool vis[R][C];

void dfs(disjoint_set<R*C> &ds, int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = true;
    int adj_emp = 0;
    for (auto [x,y] : d4) {
        if (out(i+x,j+y)) continue;
        if (s[i+x][j+y] == '.') adj_emp++;
    }
    if (adj_emp > 1) ds.v[ds.find(N(i,j))] = -2;
    for (auto [x,y] : d4) {
        if (out(i+x,j+y)) continue;
        if (adj_emp == 1 and s[i+x][j+y] == '.') {
            if (ds.v[ds.find(N(i,j))] != -2) {
                if (ds.v[ds.find(N(i,j))] >= 0 and ds.v[ds.find(N(i,j))] != N(i+x,j+y))
                    ds.v[ds.find(N(i,j))] = -2;
                else
                    ds.v[ds.find(N(i,j))] = N(i+x,j+y);
            }
        }
    }
    for (auto [x,y] : d4) {
        if (out(i+x,j+y)) continue;
        if (s[i+x][j+y] == 'W') {
            ds.merge(N(i,j), N(i+x,j+y));
            dfs(ds,i+x,j+y);
        }
    }
}

void precalc() {
    freopen("/Users/dohoon/Downloads/ready_go_part_2_input.txt", "r", stdin);
    freopen("/Users/dohoon/Downloads/ready_go_part_2_output.txt", "w", stdout);
}
void solution(int tc) {
    cin >> r >> c;
    rep(i,1,r) rep(j,1,c) {
        cin >> s[i][j];
    }
    fill(vis[0],vis[R],0);
    disjoint_set<R*C> ds;
    rep(i,1,r) rep(j,1,c) {
        if (s[i][j] == 'W') dfs(ds,i,j);
    }
    int cnt[R*C]{};
    int ans = 0;
    rep(i,1,r) rep(j,1,c) {
        if (s[i][j] == 'W') {
            if (N(i,j) == ds.find(N(i,j))) {
                if (ds.v[ds.find(N(i,j))] >= 0) {
                    cnt[ds.v[ds.find(N(i,j))]] += ds.size(N(i,j));
                } else if (ds.v[ds.find(N(i,j))] == -1) {
                    ans += ds.size(N(i,j));
                }
            }
        }
    }
    ans += *max_element(cnt,cnt+R*C);
    cout << "Case #" << tc << ": " << ans << '\n';
}
