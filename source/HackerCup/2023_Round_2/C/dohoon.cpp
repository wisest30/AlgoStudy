// 작성한 글입니다!
// https://mathsciforstudent.tistory.com/375

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

const int N = 1e6+3, M = 1e5+3;
int n;
vi adj[N];
map<string,vi> black;
int sub_leaf[N], in[N], out[N];
set<int> leaf;

int cnt = 0;
void dfs(int s = 1) {
    in[s] = ++cnt;
    if (!siz(adj[s])) sub_leaf[s]++, leaf.insert(in[s]);
    for (auto u : adj[s]) dfs(u), sub_leaf[s] += sub_leaf[u];
    out[s] = cnt;
}

void precalc() {
    freopen("/Users/dohoon/Downloads/wiki_race_input.txt", "r", stdin);
    freopen("/Users/dohoon/Downloads/wiki_race_output.txt", "w", stdout);
}
void clear() {
    cnt = 0;
    rep(i,1,n) adj[i].clear(), sub_leaf[i]=0;
    black.clear();
    leaf.clear();
}
void solution(int tc) {
    cin >> n;
    rep(i,2,n) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    rep(i,1,n) {
        int m; cin >> m;
        rep(j,1,m) {
            string s; cin >> s;
            black[s].push_back(i);
        }
    }
    dfs();
    int ans = 0;
    for (auto &[str,b] : black) if (siz(b) >= siz(leaf)) {
        sort(all(b),[&](int x, int y){ return sub_leaf[x] < sub_leaf[y]; });
        b.erase(unique(all(b)),end(b));
        set<int> s = leaf;
        bool flag = true;
        for (auto v : b) {
            auto it = s.lower_bound(in[v]);
            if (it != end(s) and *it <= out[v]) {
                it = s.erase(it);
                if (it != end(s) and *it <= out[v])
                    flag = false;
            }
        }
        if (flag) ans++;
    }
    cout << "Case #" << tc << ": " << ans << '\n';
    clear();
}
