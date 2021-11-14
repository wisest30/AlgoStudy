#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class DisjointSet {
    vector<int> G, Gmin;
public :
    DisjointSet(int n) : G(n), Gmin(n)
    { 
        iota(G.begin(), G.end(), 0);
        iota(Gmin.begin(), Gmin.end(), 0);
    }

    int find(int x) {
        if(G[x] == x) return x;
        return G[x] = find(G[x]);
    }

    bool merge(int x, int y) {
        int gx = find(x), gy = find(y);
        if(gx == gy) return false;
        if(gx < gy) swap(gx, gy);
        G[gy] = gx;
        Gmin[gx] = Gmin[gy];
        return true;
    }

    int find_min(int x) { return Gmin[find(x)]; }
};

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> A(n);
    for(auto i = 0; i < n; ++i)
        A[i] = s[i] - '0';

    vector<set<int>> S(10);
    for(auto i = 0; i < n-1; ++i) {
        if((A[i] + 1) % 10 == A[i+1])
            S[A[i]].insert(i);
    }

    DisjointSet ds(n);
    int cur = 0;
    int skip_cnt = 0;
    while(true) {
        if(skip_cnt > 10) break;
        if(S[cur].empty()) skip_cnt++;
        else skip_cnt = 0;

        vector<int> nxts, prevs;
        for(auto cur_g : S[cur]) {
            auto nxt_g = ds.find(cur_g + 1);
            A[nxt_g] = (A[nxt_g] + 1) % 10;
            ds.merge(cur_g, nxt_g);
            nxts.push_back(nxt_g);
            auto ming = ds.find_min(cur_g);
            auto prev = ming - 1;
            prevs.push_back(prev);
        }

        S[cur].clear();
        for(auto cur_g : nxts)
            for(auto i = 0; i < 10; ++i)
                S[i].erase(cur_g);
        for(auto cur_g : prevs)
            for(auto i = 0; i < 10; ++i)
                S[i].erase(cur_g);

        for(auto cur_g : nxts) {
            if(cur_g != n-1) {
                auto nxt_g = ds.find(cur_g + 1);
                if((A[cur_g] + 1) % 10 == A[nxt_g]) {
                    S[A[cur_g]].insert(cur_g);
                }
            }

            auto cur_ming = ds.find_min(cur_g);
            if(cur_ming != 0) {
                auto prev_g = cur_ming - 1;
                if((A[prev_g] + 1) % 10 == A[cur_g]) {
                    S[A[prev_g]].insert(prev_g);
                }
            }
        }

        cur = (cur + 1) % 10;
    }

    string ret;
    for(auto i = 0; i < n; ++i)
        if(i == ds.find(i)) ret.push_back('0' + A[i]);
    
    cout << ret << '\n';
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
