#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> left(m, -1), right(m, -1);
    int i = 0, j = 0;
    while(j < m) {
        if(s[i] == t[j]) {
            if(left[j] == -1) left[j] = i;
            ++i, ++j;
        }
        else
            ++i;
    }

    i = n-1, j = m-1;
    while(j >= 0) {
        if(s[i] == t[j]) {
            if(right[j] == -1) right[j] = i;
            --i, --j;
        }
        else
            --i;
    }

    auto ret = 0;
    for(auto i = 0; i < m - 1; ++i)
        ret = max(ret, right[i+1] - left[i]);
    
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
       // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
