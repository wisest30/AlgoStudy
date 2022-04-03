#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& d) {
    sort(d.begin(), d.end());
    int res = 1;
    for(auto& n : d)  {
        if(n >= res)
            res++;
    }
    return res - 1;
}

int main() {
    int tc;
    cin>>tc;
    for(int i = 1; i <= tc; i++) {
        int n;
        cin>>n;
        vector<int> d(n);
        for(int i = 0; i < n;i++) cin>>d[i];
        cout<<"Case #"<<i<<": "<<solve(d)<<endl;
    }
    return 0;
}
