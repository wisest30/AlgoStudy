#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    map<int, int> m;
    { // counstruct m
        bool dec_jump = true;
        int save_distance = 4 * n - 6, pos = 1, jump = n;
        while(save_distance > 0) {
            m[save_distance] = pos;
            pos += jump;

            if(dec_jump) jump--;
            save_distance -= 2;
            dec_jump ^= 1;
        }
    }

    vector<int> A;
    { // construct A
        int need = n * n - 1 - k, save_distance = 4 * n - 6;
        while(need && save_distance > 0) {
            if(save_distance > need)
                save_distance -= 2;
            else {
                A.push_back(save_distance);
                need -= save_distance;
                save_distance -= 8;
            }
        }

        if(need) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    cout << A.size() << "\n";
    for(auto a : A) {
        cout << m[a] << " " << (m[a] + a + 1) << "\n";
    }
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

