#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    deque<int> A(n);
    for(auto& x : A) cin >> x;

    int zero_cnt = 0;
    while(A.size() > 1) {
        while(A.size() > 1 && A.front() == 0) {
            A.pop_front();
            zero_cnt++;
        }

        if(A.size() == 1) break;

        for(auto i = (int) A.size() - 1; i >= 1; --i)
            A[i] -= A[i-1];

        if(zero_cnt) zero_cnt--;
        else A.pop_front();

        sort(A.begin(), A.end());
    }

    cout << A.back() << endl;
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
