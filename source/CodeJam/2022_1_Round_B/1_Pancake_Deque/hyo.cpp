#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    deque<int> dq(n);
    for(auto& x : dq) cin >> x;

    int ret = 0, cur_max = 0;
    while(!dq.empty()) {
        if(dq.front() < dq.back()) {
            if(dq.front() >= cur_max)
                ++ret, cur_max = dq.front();
            dq.pop_front();
        } else {
            if(dq.back() >= cur_max)
                ++ret, cur_max = dq.back();
            dq.pop_back();
        }
    }

    cout << ret << "\n";
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