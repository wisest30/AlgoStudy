#include <bits/stdc++.h>
using namespace std;

string solve(vector<vector<int>>& c) {
    int req = 1e6;
    vector<int> mi(4, INT_MAX);
    for(auto& row : c) {
        for(int i = 0; i < 4; i++)
            mi[i] = min(mi[i], row[i]);
    }
    if(accumulate(begin(mi), end(mi),0) < req)
        return "IMPOSSIBLE";

    for(int i = 0; i < 4; i++) {
        mi[i] = min(mi[i], req);
        req -= mi[i];
    }

    return to_string(mi[0])  + ' ' + to_string(mi[1])  + ' ' +  to_string(mi[2])  + ' ' + to_string(mi[3]);
}

int main() {
    int tc;
    cin>>tc;
    vector<vector<int>> c(3, vector<int>(4));
    for(int i = 1; i <= tc; i++) {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 4; j++)
                cin>>c[i][j];
        cout<<"Case #"<<i<<": "<<solve(c)<<endl;
    }
    return 0;
}
