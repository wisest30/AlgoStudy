#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;

int query(int l, int r) {
    l++;
    cout << "M " << l << " " << r << endl;
    int x;
    cin >> x;
    x--;
    return x;
}

void swap(int i, int j) {
    i++, j++;
    cout << "S " << i << " " << j << endl;
    int x;
    cin >> x;

    if(x != 1) exit(0);
}

void answer() {
    cout << "D" << endl;
    int x;
    cin >> x;
    if(x != 1) exit(0);
}

void solve(int TestCase) {
    for(auto i = 0; i < n-1; ++i) {
        auto x = query(i, n);
        if(i != x) swap(i, x);
    }

    answer();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t >> n;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
