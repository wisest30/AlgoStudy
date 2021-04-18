#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void output(int color, int y, int x) {
    cout << color << " " << y << " " << x << endl;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<pair<int, int>> even, odd;
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < n; ++j)
            if((i + 1 + j + 1) % 2) odd.push_back({i + 1, j + 1});
            else even.push_back({i + 1, j + 1});
    
    for(auto i = 0; i < n * n; ++i) {
        int x;
        cin >> x;

        if(!odd.empty() && !even.empty()) {
            if(x == 2) {
                output(1, odd.back().first, odd.back().second);
                odd.pop_back();
            }
            else {
                output(2, even.back().first, even.back().second);
                even.pop_back();
            }
        }
        else if(odd.empty()) {
            output(x == 3 ? 2 : 3, even.back().first, even.back().second);
            even.pop_back();
        }
        else if(even.empty()) {
            output(x == 3 ? 1 : 3, odd.back().first, odd.back().second);
            odd.pop_back();
        }
        else
            assert(false);
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
