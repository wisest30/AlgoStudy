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

mt19937 rng(random_device{}());
#define my_random(l,r) uniform_int_distribution<ll>(l,r)(rng)
#define my_shuffle(...) shuffle(__VA_ARGS__,rng)

struct rabin_karp {
    const ll A, B; vector<ll> h, p;
    rabin_karp(const vi &s, ll a, ll b):
    A(a), B(b), h(siz(s)), p(siz(s)) { // 1-based string
        assert(siz(s)), p[0] = 1;
        rep(i,1,siz(s)-1) {
            h[i] = (h[i-1]*A+s[i])%B;
            p[i] = p[i-1]*A%B;
        }
    }
    ll hash(int a, int b) { // closed form
        assert(a <= b);
        ll r = (h[b]-h[a-1]*p[b-a+1])%B;
        return r >= 0 ? r : r+B;
    }
};
template <class T> struct PURQ {
    int N; vector<T> t; T (*op)(T,T);
    void set(int n, T e, T f(T,T)) { N=n, t.resize(2*N,e), op=f; }
    void update(int k, T v) {
        ensure(0 <= k and k < N);
        for (t[k += N] = v; (k /= 2) >= 1; t[k] = op(t[2*k],t[2*k+1]));
    }
    T query(int a, int b) {
        ensure(0 <= a and a-1 <= b and b < N);
        T l = t[0], r = t[0];
        for (a += N, b += N; a <= b; ++a /= 2, --b /= 2) {
            if (a&1) l = op(l,t[a]);
            if (~b&1) r = op(t[b],r);
        }
        return op(l,r);
    }
};

void precalc() {
    freopen("/Users/dohoon/Downloads/meta_game_input.txt", "r", stdin);
    freopen("/Users/dohoon/Downloads/meta_game_output.txt", "w", stdout);
}
void solution(int tc) {
    int n; cin >> n;
    vi a(n), b(n), vals;
    for(auto &e:a)cin>>e,vals.pb(e);
    for(auto &e:b)cin>>e,vals.pb(e);
    sort(all(vals)),vals.erase(unique(all(vals)),end(vals));
    for(auto &e:a)e=lower_bound(all(vals),e)-begin(vals)+3;
    for(auto &e:b)e=lower_bound(all(vals),e)-begin(vals)+3;
    
    a.insert(end(a),all(b));
    a.insert(end(a),all(a));
    a.insert(begin(a),0);
    
    PURQ<int> diff;
    diff.set(3*n+1,1,[](int x,int y){return min(x,y);});
    rep(i,1,3*n) {
        diff.update(i,a[n+i]-a[i]);
    }
    
    vi t = a;
    ll x = my_random(1e7,7e8);
    rabin_karp h1(a,x,998'244'353);
    rabin_karp hh1(a,x,998'244'353);
    a.push_back(0), reverse(all(a)), a.pop_back();
    rabin_karp h2(a,x,998'244'353);
    rabin_karp hh2(a,x,998'244'353);
    
    int ans = -1;
    
    rep(i,1,2*n) {
        int l = i, m = i+n/2-1, b = i+n-1;
        if (diff.query(l,m)>0) {
            if (h1.hash(l,b) == h2.hash(3*n-b+1,3*n-l+1)) {
                if (hh1.hash(l,b) == hh2.hash(3*n-b+1,3*n-l+1)) {
                    ans = i-1;
                    break;
                }
            }
        }
    }
    
    cout << "Case #" << tc << ": " << ans << '\n';
}
