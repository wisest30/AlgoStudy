#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k, r, p;
    cin >> n >> k >> r >> p;

    if(k >= n) {
        ll ret = 0;
        for(auto i = 1; i <= n; ++i) {
            cout << "T " << i << endl;

            cin >> r >> p;
            ret += p;
        }

        ret /= 2;
        cout << "E " << ret << endl;
    } else {
        vector<double> cnts1(n + 1), cnts2(n + 1);
        cnts1[r] = p;
        for(auto i = 0; i < k; ++i) {
            if(i % 2 == 0) {
                for(auto j = 1; j <= n; ++j) {
                    if(cnts1[j] == 0 && cnts2[j] == 0) {
                        cout << "T " << j << endl;

                        cin >> r >> p;
                        cnts1[r] = p;

                        break;
                    }
                }
            } else {
                cout << "W" << endl;

                cin >> r >> p;
                cnts2[r] = p;
                cnts1[r] = 0;
            }
        }

        double room_cnt1 = 0, total_cnt1 = 0;
        for(auto cnt : cnts1)
            if(cnt > 0)
                ++room_cnt1, total_cnt1 += cnt;
        
        double avg1 = total_cnt1 / room_cnt1;

        double room_cnt2 = 0, total_cnt2 = 0;
        for(auto cnt : cnts2)
            if(cnt > 0)
                ++room_cnt2, total_cnt2 += cnt;
        
        ll ret = avg1 * (n - room_cnt2) + total_cnt2;
        ret /= 2;
        cout << "E " << ret << endl;
    }
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
