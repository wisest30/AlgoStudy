#include<bits/stdc++.h>
 
using namespace std;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<long long> A(n);
    for(auto& x : A)
        cin >> x;
    
    vector<long long> D(n-1);
    long long positive_sum = 0;
    for(auto i = 0; i < n-1; ++i) {
        D[i] = A[i+1] - A[i];
        if(D[i] > 0)
            positive_sum += D[i];
    }
    
    long long first = A[0];
    auto get_ans = [&]() {
        if((positive_sum + first) % 2 == 0)
            return (positive_sum + first) / 2;
        else           
            return (positive_sum + first + 1) / 2;
    };

    cout << get_ans() << endl;

    int q;
    cin >> q;
    for(auto i = 0; i < q; ++i) {
        long long l, r, x;
        cin >> l >> r >> x;
        l--, r--;

        if(l == 0)
            first += x;
        else {
            auto old_val = D[l-1];
            auto new_val = old_val + x;
            D[l-1] = new_val;

            positive_sum += max(0ll, new_val) - max(0ll, old_val);
        }

        if(r < D.size()) {
            auto old_val = D[r];
            auto new_val = old_val - x;
            D[r] = new_val;

            positive_sum += max(0ll, new_val) - max(0ll, old_val);
        }

        cout << get_ans() << endl;
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
