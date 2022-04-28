#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    vector<vector<string>> P(4);
    P[0].push_back("1");

    for(auto i = 1; i < 4; ++i) {
        for(auto& s : P[i-1])
            P[i].push_back(s + s);
        
        for(auto& s : P[i-1]) {
            P[i].push_back(s + string(1 << (i - 1), '0'));
            for(auto& t : P[i-1])
                P[i].push_back(t + t);
        }
    }

    for(auto& s : P[3]) {
        cout << s << endl;

        int n;
        cin >> n;

        if(n == 0)
            break;
        else if(n == -1)
            exit(0);
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