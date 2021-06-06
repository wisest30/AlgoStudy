#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<vector<int>> G1, G2;
vector<pair<int, int>> T;
set<pair<int, int>> timeLine;
int curTime;

void dfsTiming(int cur) {
    T[cur].first = curTime++;

    for(auto nxt : G2[cur])
        dfsTiming(nxt);
    
    T[cur].second = curTime++;
}

int dfsMaxCnt(int cur) {
    bool innerOver = false, outerOver = false;
    pair<int, int> outerOverTime;

    auto p = timeLine.lower_bound(T[cur]);
    if(p != timeLine.end() && p->first < T[cur].second)
        innerOver = true;
    else if(p != timeLine.begin() && prev(p)->second > T[cur].second)  {
        outerOver = true;
        outerOverTime = *prev(p);
        timeLine.erase(prev(p));
        timeLine.insert(T[cur]);
    }
    else
        timeLine.insert(T[cur]);

    int ret = timeLine.size();
    for(auto nxt : G1[cur])
        ret = max(ret, dfsMaxCnt(nxt));
    
    if(innerOver); //pass
    else if(outerOver) {
        timeLine.erase(T[cur]);
        timeLine.insert(outerOverTime);
    }
    else
        timeLine.erase(T[cur]);

    return ret;
}

void solve(int TestCase) {
    int n;
    cin >> n;
    G1 = vector<vector<int>>(n);
    G2 = vector<vector<int>>(n);
    T = vector<pair<int, int>>(n);
    timeLine.clear();
    curTime = 0;

    for(auto v = 1; v < n; ++v) {
        int u;
        cin >> u;
        u--;

        G1[u].push_back(v);
    }

    for(auto v = 1; v < n; ++v) {
        int u;
        cin >> u;
        u--;

        G2[u].push_back(v);
    }

    dfsTiming(0);
    auto ret = dfsMaxCnt(0);
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
//        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
