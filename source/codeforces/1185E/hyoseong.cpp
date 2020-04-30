#include<bits/stdc++.h>
 
using namespace std;

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;
    
    auto A = vector<string>(r);
    for(auto i = 0; i < r; ++i)
        cin >> A[i];

    auto alpha_pos = vector<vector<pair<int, int>>>(26);
    for(auto i = 0; i < r; ++i)
    {
        for(auto j = 0; j < c; ++j)
        {
            if(A[i][j] == '.')
                continue;
            auto alpha = A[i][j];
            auto idx = alpha - 'a';
            alpha_pos[idx].push_back({i, j});
        }
    }

    for(auto i = 0; i < alpha_pos.size(); ++i) {
        if((int)alpha_pos[i].size() > max(r, c)) {
            cout << "NO" << endl;
            return;
        }

        bool same_row = true;
        bool same_col = true;
        for(auto j = 0; j < alpha_pos[i].size(); ++j)
        {
            if(alpha_pos[i][j].first != alpha_pos[i][0].first)
                same_row = false;
            if(alpha_pos[i][j].second != alpha_pos[i][0].second)
                same_col = false;
        }

        if(!same_row && !same_col) {
            cout << "NO" << endl;
            return;
        }

        sort(alpha_pos[i].begin(), alpha_pos[i].end());
    }

    auto ret = vector<vector<int>>{};
    for(auto i = (int)alpha_pos.size() - 1; i >= 0; --i)
    {
        if(alpha_pos[i].empty()) {
            if(!ret.empty())
                ret.push_back(ret[0]);
            continue;
        }

        if(alpha_pos[i].size() == 1) {
            ret.push_back({alpha_pos[i][0].first,
                            alpha_pos[i][0].second,
                            alpha_pos[i][0].first,
                            alpha_pos[i][0].second});
            
            continue;
        }

        bool same_row = alpha_pos[i][0].first == alpha_pos[i][1].first;
        auto y = alpha_pos[i][0].first;
        auto x = alpha_pos[i][0].second;
        auto c = 'a' + i;
        while(true) {
            if(same_row && x > alpha_pos[i].back().second)
                break;
            if(!same_row && y > alpha_pos[i].back().first)
                break;
            
            if(A[y][x] < c) {
                cout << "NO" << endl;
                return;
            }

            if(same_row)
                x++;
            else
                y++;
        }

        ret.push_back({alpha_pos[i][0].first,
                        alpha_pos[i][0].second,
                        alpha_pos[i].back().first,
                        alpha_pos[i].back().second});
    }

    reverse(ret.begin(), ret.end());
    cout << "YES" << endl;
    cout << ret.size() << endl;
    for(auto i = 0; i < ret.size(); ++i)
    {
        for(auto j = 0; j < 4; ++j)
            cout << (ret[i][j] + 1) << " ";
        cout << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
