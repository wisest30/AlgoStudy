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

const int maxp = 3188646, INF = 1000;
int dp[maxp+1][42];
int rp[maxp+1][42];

void precalc() {
    freopen("/Users/dohoon/Downloads/sum_41_chapter_2_input.txt","r",stdin);
    freopen("/Users/dohoon/Downloads/sum_41_chapter_2_output.txt","w",stdout);
    fill(dp[0],dp[maxp+1],INF), dp[1][0] = 0;
    rep(i,1,maxp) rep(j,0,41) {
        rep(k,1,41) {
            if (i*k > maxp or j+k > 41) break;
            if (dp[i*k][j+k] > dp[i][j]+1) {
                dp[i*k][j+k] = dp[i][j]+1;
                rp[i*k][j+k] = k;
            }
        }
    }
}
void solution(int tc) {
    int p; cin >> p;
    if (p > maxp) { print(-1); return; }
    if (dp[p][41] == INF) { print(-1); return; }
    
    vector<int> track;
    int i = p, j = 41, k;
    while (rp[i][j] > 0) {
        track.pb(k = rp[i][j]);
        i /= k, j -= k;
    }
    
    if (i == 1 and j == 0) {
        cout << "Case #" << tc << ": " << siz(track) << ' ';
        for (auto t : track) cout << t << ' ';
        cout << '\n';
    } else print(-1);
}
