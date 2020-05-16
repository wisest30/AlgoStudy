#include<bits/stdc++.h>
 
using namespace std;

void solve(int TestCase) {
    string s;
    cin >> s;
    int query_cnt;
    cin >> query_cnt;
    
    auto query = vector<pair<int, int>>(query_cnt);
    for(auto i = 0; i < query_cnt; ++i)
        cin >> query[i].first >> query[i].second;

    int n = s.size();
    auto alpha_cnt = vector<vector<int>>(n, vector<int>(26));
    for(auto i = 0; i < n; ++i)
    {
        int idx = s[i] - 'a';
        alpha_cnt[i][idx]++;
    }

    auto alpha_cnt_ps = vector<vector<int>>(n + 1, vector<int>(26));
    for(auto i = 1; i < alpha_cnt_ps.size(); ++i) {
        for(auto j = 0; j < 26; ++j) {
            alpha_cnt_ps[i][j] = alpha_cnt_ps[i-1][j] + alpha_cnt[i-1][j];
        }
    }

    for(auto i = 0; i < query.size(); ++i)
    {
        int left = query[i].first;
        int right = query[i].second;
        left--;

        int exist_cnt = 0;
        for(auto j = 0; j < 26; ++j)
        {
            int cnt = alpha_cnt_ps[right][j] - alpha_cnt_ps[left][j];
            if(cnt > 0)
                exist_cnt++;
        }

        if(right - left == 1)
            cout << "Yes" << endl;
        else if(s[left] != s[right-1])
            cout << "Yes" << endl;
        else if(exist_cnt > 2)
            cout << "yes" << endl;
        else
            cout << "No" << endl;
    }    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
