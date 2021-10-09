#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class FenwickTree {
public:
    int N;
    vector<long long> f;
    FenwickTree(int N) : N(N), f(vector<long long>(N+10)) {}
    void upd(int i, long long val) {
        assert(i >= 0 && i < N);
        for(; i < f.size(); i |= i+1) f[i] += val;
    }

    long long get(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 0;
        i--;

        long long ret = 0;
        for(; i >= 0; i = (i & (i+1)) - 1) ret += f[i];
        return ret;
    }

    long long get(int l, int r) {
        assert(l >= 0 && l <= N);
        assert(r >= 0 && r <= N);
        return get(r) - get(l);
    }

    // upper_bound get(i) <= k
    int upper_bound(long long k) {
        if(get(N) <= k)
            return N;

        int i = 0, right = 0;
        long long sum = 0;
        while((1 << (i + 1)) <= N) ++i;
        while(true) {
            while(right + (1 << i) - 1 >= N) --i;
            auto nxt_sum = sum + f[right + (1 << i) - 1];
            if(nxt_sum <= k) {
                sum = nxt_sum;
                right |= 1 << i;
            }
            if(i == 0 || right == N) break;
            else --i;
        }

        return right;
    }
};

bool f25(vector<int>& A, vector<int>& B, vector<ll>& L, int k) {
    int n = L.size();
    unordered_map<ll, int> m;
    vector<ll> dp(1 << n);
    for(auto i = 0; i < n; ++i)
        dp[1 << i] = L[i];
    for(auto mask = 1; mask < (1 << n); ++mask) {
        dp[mask] = dp[mask & -mask] + dp[mask & (mask - 1)];
        if(m.count(dp[mask])) {
            int a = m[dp[mask]];
            int b = mask;
            int c = a & b;
            a -= c, b -= c;

            for(auto i = 0; i < n; ++i) {
                if(a & (1 << i)) A.push_back(i + 1);
                else if(b & (1 << i)) B.push_back(i + 1);
            }

            return true;
        }
        m[dp[mask]] = mask;
    }

    return false;
}

void f100(vector<int>& A, vector<int>& B, vector<ll>& L, int k) {
    int n = L.size();
    vector<int> I(n);
    iota(I.begin(), I.end(), 1);

    while(n > k) {
        vector<ll> l;
        vector<int> a, b, idxes;
        int m = min(25, n);
        for(auto i = 0; i < m; ++i) {
            l.push_back(L.back());
            L.pop_back();

            idxes.push_back(I.back());
            I.pop_back();
        }

        f25(a, b, l, k);

        unordered_set<int> as(a.begin(), a.end()), bs(b.begin(), b.end());
        for(auto i = 1; i <= m; ++i) {
            if(as.count(i)) {
                A.push_back(idxes[i-1]);
            } else if(bs.count(i)) {
                B.push_back(idxes[i-1]);
            } else {
                L.push_back(l[i-1]);
                I.push_back(idxes[i-1]);
            }
        }

        n = L.size();
    }
}

void f1000(vector<int>& A, vector<int>& B, vector<ll>& L, int k) {
    auto random_address = []{char *pt = new char;delete pt;return uint64_t(pt);};
    const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
    mt19937_64 rng(SEED);

    vector<int> I(L.size());
    iota(I.begin(), I.end(), 1);

    while(L.size() > 100) {
        unordered_map<ll, string> m;

        while(true) {
            string s(L.size(), 0);
            ll su = 0;
            for(auto i = 0; i < s.size(); ++i)
                if(rng() % 2) s[i] = 1, su += L[i];
            if(m.count(su)) {
                auto& t = m[su];
                vector<ll> nxtL;
                vector<int> nxtI;
                for(auto i = 0; i < L.size(); ++i) {
                    if(s[i] && !t[i]) A.push_back(I[i]);
                    else if(!s[i] && t[i]) B.push_back(I[i]);
                    else nxtL.push_back(L[i]), nxtI.push_back(I[i]);
                }
                swap(nxtL, L);
                swap(nxtI, I);
                break;
            } else {
                m[su] = s;
            }
        }
    }

    if(!L.empty()) {
        vector<int> a, b;
        f100(a, b, L, k);
        for(auto x : a) A.push_back(I[x - 1]);
        for(auto x : b) B.push_back(I[x - 1]);
    }
}

void f200000(vector<int>& A, vector<int>& B, vector<ll>& L, int k) {
    unordered_map<ll, int> m;
    vector<bool> removed(L.size());
    int rmcnt = 0;
    for(auto i = 0; i < L.size(); ++i) {
        if((int)L.size() - rmcnt <= 1000)
            break;

        auto p = m.find(L[i]);
        if(p != m.end()) {
            rmcnt += 2;
            A.push_back(p->second + 1);
            B.push_back(i + 1);
            removed[p->second] = removed[i] = true;
            m.erase(p);
        } else {
            m[L[i]] = i;
        }
    }

    vector<ll> nxtL;
    vector<int> I;
    nxtL.reserve(L.size());
    for(auto i = 0; i < L.size(); ++i)
        if(!removed[i]) nxtL.push_back(L[i]), I.push_back(i + 1);
    
    swap(L, nxtL);
    while(L.size() > 1000) {
        int n = L.size();
        FenwickTree ft(n);
        unordered_map<ll, pair<int, int>> m;
        vector<vector<ll>> added(n);
        for(auto i = 0; i < n; ++i) ft.upd(i, 1);
        for(auto len = 1; len < n; ++len) {
            auto cnt = ft.get(n);
            if(cnt <= 1000 || cnt <= len) break;
            for(ll k = 1; k <= ft.get(n); ++k) {
                auto cnt = ft.get(n);
                if(cnt <= 1000) break;
                if(k + len > cnt) break;

                auto i = ft.upper_bound(k - 1);
                auto j = ft.upper_bound(k + len - 1);

                ll su = L[i] + L[j];
                auto p = m.find(su);
                if(p != m.end()) {
                    auto [x, y] = p->second;
                    vector<int> C{i, j, x, y};
                    for(auto a : C) {
                        ft.upd(a, -1);
                        for(auto su : added[a])
                            if(m.count(su)) m.erase(su);
                    }

                    A.push_back(I[i]);
                    A.push_back(I[j]);
                    B.push_back(I[x]);
                    B.push_back(I[y]);
                    --k;
                } else {
                    m[su] = make_pair(i, j);
                    added[i].push_back(su);
                    added[j].push_back(su);
                }
            }
        }

        vector<ll> nxtL;
        vector<int> nxtI;
        for(auto i = 0; i < n; ++i)
            if(ft.get(i, i+1))
                nxtL.push_back(L[i]), nxtI.push_back(I[i]);
        swap(L, nxtL);
        swap(I, nxtI);
    }

    if(!L.empty()) {
        vector<int> a, b;
        f1000(a, b, L, k);

        for(auto x : a) A.push_back(I[x-1]);
        for(auto x : b) B.push_back(I[x-1]);
    }
}
/*
void valid_check(vector<int> A, vector<int> B, vector<ll> L, int k) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    assert(!A.empty());
    assert(!B.empty());
    ll su0 = 0, su1 = 0;
    unordered_set<int> s;
    for(auto i : A) {
        assert(!s.count(i));
        assert(i <= (int)L.size());
        s.insert(i);
        su0 += L[i-1];
    }
    for(auto i : B) {
        assert(!s.count(i));
        assert(i <= (int)L.size());
        s.insert(i);
        su1 += L[i-1];
    }
    assert(su0 == su1);
    assert((int)A.size() + (int)B.size() >= (int)L.size() - k);
}

vector<ll> random_input(int n) {    
    auto random_address = []{char *pt = new char;delete pt;return uint64_t(pt);};
    const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
    mt19937_64 rng(SEED);

    vector<ll> ret(n);
    for(auto i = 0; i < n; ++i) ret[i] = rng() % 200000 + 1;
    return ret;
}
*/

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    vector<ll> L(n);
    for(auto& x : L) cin >> x;
    //n = 200000, k = 25;
    //auto L = random_input(n);

    vector<int> A, B;
    bool possible = true;

    auto copyL = L;
    if(n <= 25) {
        possible = f25(A, B, L, k);
    } else if(n <= 100) {
        f100(A, B, L, k);
    } else if(n <= 1000) {
        f1000(A, B, L, k);
    } else {
        f200000(A, B, L, k);
    }

    if(possible) {
        cout << "Possible\n";
        for(auto x : A) cout << x << " ";
        cout << '\n';
        for(auto x : B) cout << x << " ";
        cout << '\n';
    } else {
        cout << "Impossible\n";
    }

    //valid_check(A, B, copyL, k);
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
