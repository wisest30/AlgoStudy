#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;
vector<string> A;

int get_need_cnt(int i, bool isRow) {
    int ret = 0;
    for(auto j = 0; j < n; ++j) {
        auto c = isRow ? A[i][j] : A[j][i];
        if(c == 'O')
            return INT_MAX;
        else if(c == '.')
            ret++;
    }

    return ret;
}

int get_case_cnt(int need_cnt) {
    if(need_cnt == 1) {
        set<pair<int, int>> s;
        for(auto isRow = 0; isRow <= 1; ++isRow) {
            for(auto i = 0; i < n; ++i) {
                if(get_need_cnt(i, isRow) != 1) continue;
                for(auto j = 0; j < n; ++j) {
                    auto c = isRow ? A[i][j] : A[j][i];
                    if(c == '.') {
                        s.insert(isRow ? make_pair(i, j) : make_pair(j, i));
                        break;
                    }
                }
            }
        }

        return s.size();
    }
    else {
        int ret = 0;
        for(auto isRow = 0; isRow <= 1; ++isRow)
            for(auto i = 0; i < n; ++i)
                if(get_need_cnt(i, isRow) == need_cnt)
                    ret++;
        return ret;
    }
}

void solve(int TestCase) {
    cin >> n;
    A = vector<string>(n);

    for(auto& x : A)
        cin >> x;

    int ret = INT_MAX;
    for(auto isRow = 0; isRow <= 1; ++isRow)
        for(auto i = 0; i < n; ++i)
            ret = min(ret, get_need_cnt(i, isRow));

    if(ret == INT_MAX) {
        cout << "Impossible" << endl;
        return;
    }

    cout << ret << " " << get_case_cnt(ret) << endl;
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
