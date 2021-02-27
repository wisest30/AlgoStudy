#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<long long> C;
void init() {
    C.push_back(5);
    for(long long a = 5; C.back() < 1e9 + 1; a += 2) {
        C.push_back((a * a + 1) / 2);
    }
}

void solve(int TestCase) {
    int n;
    cin >> n;

    auto ret = upper_bound(C.begin(), C.end(), n) - C.begin();
    cout << ret << endl;

}
 
int main(){
    init();
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
