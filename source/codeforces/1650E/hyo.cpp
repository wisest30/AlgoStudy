#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, d;
    cin >> n >> d;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    auto can_move = [&](auto i, auto m) {
        if(i < 0) return false;

        auto B = A;
        B.erase(B.begin() + i);

        bool can_place = d - B.back() - 1 >= m;
        for(auto i = 0; i < B.size(); ++i) {
            auto gap = i == 0 ? B[i] - 1 : B[i] - B[i-1] - 1;
            if(gap < m) return false;
            if(gap >= 2 * m + 1) can_place = true;
        }

        return can_place;
    };

    auto check = [&](auto m) {
        for(auto i = 0; i < n; ++i) {
            auto gap = i == 0 ? A[i] - 1 : A[i] - A[i-1] - 1;
            if(gap < m)
                return can_move(i-1, m) || can_move(i, m);
        }

        return true;
    };

    auto l = 0, r = d;
    while(l + 1 < r) {
        auto m = (l + r) / 2;
        if(check(m)) l = m;
        else r = m;
    }

    cout << l << endl;
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
