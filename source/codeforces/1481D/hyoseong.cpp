#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<string> edges(n);
    for(auto& x : edges) cin >> x;

    for(auto i = 0; i < n; ++i) {
        for(auto j = i + 1; j < n; ++j) {
            if(edges[i][j] == edges[j][i]) {
                cout << "YES" << endl;
                for(auto k = 0; k < m + 1; ++k)
                    cout << (k % 2 ? i+1:j+1) << " ";
                cout << endl;
                return;
            }
        }
    }

    if(m % 2 == 1) {
        cout << "YES" << endl;
        for(auto k = 0; k < m + 1; ++k)
            cout << (k % 2 + 1) << " ";
        cout << endl;
    }
    else if(n == 2) {
        cout << "NO" << endl;
    }
    else if(edges[0][1] == edges[1][2] && edges[1][2] == edges[2][0]) {
        cout << "YES" << endl;
        for(auto k = 0; k < m + 1; ++k)
            cout << (k % 3 + 1) << " ";
        cout << endl;
    }
    else {
        cout << "YES" << endl;

        int node[3];
        for(auto i = 0; i < 3; ++i) {
            if(edges[i][(i+1) % 3] != edges[i][(i+2) % 3]) {
                node[0] = i + 1;
                node[1] = (i + 1) % 3 + 1;
                node[2] = (i + 2) % 3 + 1;
                break;
            }
        }

        if(m % 4 == 0) {
            for(auto k = 0; k < m / 2; ++k)
                cout << node[k % 2] << " ";
            for(auto k = 0; k < m / 2; ++k)
                cout << node[k % 2 == 0 ? 0 : 2] << " ";
            cout << node[0] << endl;
        }
        else {
            for(auto k = 0; k < m / 2; ++k)
                cout << node[(k % 2) ^ 1] << " ";
            for(auto k = 0; k < m / 2; ++k)
                cout << node[k % 2 == 0 ? 0 : 2] << " ";
            cout << node[2] << endl;
        }
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
 
