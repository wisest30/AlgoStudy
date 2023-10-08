#pragma region orange!orange!orange!orange!
// g++-12 -std=c++17 -O2 -Wall -Wno-unknown-pragmas -DLOCAL
#include <bits/stdc++.h>
#define rep(i,a,b) for (auto i = (a); i <= (b); ++i)
#define per(i,a,b) for (auto i = (b); i >= (a); --i)
#define siz(x) int(x.size())
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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

#define FC(a) [](const auto &x, const auto &y){return a;}
#define print(x) cout << "Case #" << tc << ": " << x << '\n';

template <class S, S (*ss)(S,S), class F, F (*ff)(F,F),
          S (*fs)(F,S), const int N = 1<<20> // N=2^k only
struct RURQ {
    S v[2*N]; F z[2*N];
    RURQ(S e, F id) { fill(v,v+2*N,e), fill(z,z+2*N,id); }
    void push(int k) {
        v[k] = fs(z[k],v[k]);
        if (k < N) z[2*k] = ff(z[2*k],z[k]), z[2*k+1] = ff(z[2*k+1],z[k]);
        z[k] = z[0];
    }
    void update(int a, int b, F f, int k = 1, int s = 0, int e = N-1) {
        push(k);
        if (a <= s and e <= b) { z[k] = f, push(k); return; }
        if (b < s or e < a) return;
        update(a,b,f,2*k,s,(s+e)/2), update(a,b,f,2*k+1,(s+e)/2+1,e);
        v[k] = ss(v[2*k],v[2*k+1]);
    }
    S query(int a, int b, int k = 1, int s = 0, int e = N-1) {
        push(k);
        if (a <= s and e <= b) return v[k];
        if (b < s or e < a) return v[0];
        return ss(query(a,b,2*k,s,(s+e)/2), query(a,b,2*k+1,(s+e)/2+1,e));
    }
    int find(int k = 1, int s = 0, int e = N-1) {
        push(k);
        if (s == e) return s;
        push(2*k), push(2*k+1);
        if (v[2*k].fi >= v[2*k+1].fi) return find(2*k,s,(s+e)/2);
        return find(2*k+1,(s+e)/2+1,e);
    }
};

ii ss(ii x, ii y) {
    return {max(x.fi,y.fi), max(x.se,y.se)};
}
bool ff(bool x, bool y) {
    return x ^ y;
}
ii fs(bool x, ii y) {
    if (x) return {y.se,y.fi};
    return y;
}

void precalc() {
    freopen("/Users/dohoon/Downloads/today_is_gonna_be_a_great_day_input.txt","r",stdin);
    freopen("/Users/dohoon/Downloads/today_is_gonna_be_a_great_day_output.txt","w",stdout);
}

void solution(int tc) {
    RURQ<ii,ss,bool,ff,fs> ds({-2e9,-2e9},0);
    
    int n; cin >> n;
    rep(i,1,n) {
        int x; cin >> x;
        ds.v[(1<<20)+i] = {x,1'000'000'007-x};
    }
    per(i,1,(1<<20)-1) ds.v[i] = ss(ds.v[2*i],ds.v[2*i+1]);
    
    int q; cin >> q;
    ll answer = 0;
    rep(i,1,q) {
        int l, r;
        cin >> l >> r;
        ds.update(l,r,1);
        int res = ds.find();
        // cerr << res << ' ' << ds.query(res,res).fi << '\n';
        answer += res;
    }
    print(answer);
}
