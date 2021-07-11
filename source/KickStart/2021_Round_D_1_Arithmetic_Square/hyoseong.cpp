    #include<bits/stdc++.h>
    
    using namespace std;
    using ll = long long;

    int f(const vector<vector<int>>& A) {
        int ret = 0;
        for(auto i = 0; i < 3; ++i) {
            if(A[i][1] - A[i][0] == A[i][2] - A[i][1]) ret++;
            if(A[1][i] - A[0][i] == A[2][i] - A[1][i]) ret++;
        }

        if(A[1][1] - A[0][0] == A[2][2] - A[1][1]) ret++;
        if(A[1][1] - A[0][2] == A[2][0] - A[1][1]) ret++;

        return ret;
    }

    void solve(int TestCase) {
        auto A = vector<vector<int>>(3, vector<int>(3));
        cin >> A[0][0] >> A[0][1] >> A[0][2];
        cin >> A[1][0] >> A[1][2];
        cin >> A[2][0] >> A[2][1] >> A[2][2];

        int ret = 0;
        A[1][1] = (A[0][0] + A[2][2]) / 2;
        ret = max(ret, f(A));
        A[1][1] = (A[0][2] + A[2][0]) / 2;
        ret = max(ret, f(A));
        A[1][1] = (A[1][0] + A[1][2]) / 2;
        ret = max(ret, f(A));
        A[1][1] = (A[0][1] + A[2][1]) / 2;
        ret = max(ret, f(A));
        
        cout << ret << endl;
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
