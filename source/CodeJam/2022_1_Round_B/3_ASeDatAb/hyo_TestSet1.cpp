#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    cout << "00000000" << endl;
    while(true) {
        int n;
        cin >> n;

        if(n == -1)
            exit(0);
        else if(n == 0)
            break;

        cout << string(n, '1') << string(8 - n, '0') << endl;
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