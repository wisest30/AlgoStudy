#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    constexpr int n = 100;
    constexpr int m = 10000;
    
    // threshold
    constexpr int T1 = 1000; // hard problem count
    constexpr int T2 = 400; // hard problem correct cnt
    constexpr int T3 = 1000; // second hard problem range1
    constexpr int T4 = 2000; // second hard problem range2

    vector<string> A(n);
    for(auto& x : A) cin >> x;

    // (problem difficulty, problem id)
    vector<pair<int, int>> Difficulty(m);
    for(auto i = 0; i < m; ++i)
        Difficulty[i].second = i;

    for(auto& x : A)
        for(auto i = 0; i < m; ++i)
            if(x[i] == '0') Difficulty[i].first++;
    
    sort(Difficulty.begin(), Difficulty.end());

    vector<int> candi;
    for(auto i = 0; i < n; ++i) {
        int correct = 0;
        for(auto j = m - T1; j < m; ++j)
            if(A[i][Difficulty[j].second] == '1') correct++;
        if(correct >= T2)
            candi.push_back(i);
    }

    auto ret = 0;
    int min_val = INT_MAX;
    for(auto i : candi) {
        int cnt = 0;
        for(auto j = m - T1; j < m; ++j)
            if(A[i][Difficulty[j].second] == '1') cnt++;
        for(auto j = m - T4; j < m - T3; ++j)
            if(A[i][Difficulty[j].second] == '1') cnt--;
        cnt = abs(cnt);
        if(cnt < min_val)
            ret = i, min_val = cnt;
    }

    ret++;
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1, p;
    cin >> t >> p;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
