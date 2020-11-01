#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 1e5 + 1;
int A[6], n, B[MAX_N], cnt[MAX_N];
pair<int, int> all[6 * MAX_N];
void solve(int TestCase) {
    for(auto i = 0; i < 6; ++i) cin >> A[i];
    cin >> n;
    for(auto i = 0; i < n; ++i) cin >> B[i];

    for(auto i = 0; i < 6; ++i)
        for(auto j = 0; j < n; ++j) {
            all[6 * j + i].first = B[j] - A[i];
            all[6 * j + i].second = j;
        }
    
    sort(all, all + 6 * n);

    int ret = INT_MAX, c = 0, i = 0, j = 0;
    while(i < 6 * n) {
        if(c == n) {
            int idx = all[i].second;
            cnt[idx]--;
            if(cnt[idx] == 0) c--;
            i++;
        }
        else if(j < 6 * n) {
            int idx = all[j].second;
            cnt[idx]++;
            if(cnt[idx] == 1) c++;
            j++;
        }
        else
            break;
        
        if(c == n)
            ret = min(ret, all[j-1].first - all[i].first);
    }

    cout << ret << endl;
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
 
