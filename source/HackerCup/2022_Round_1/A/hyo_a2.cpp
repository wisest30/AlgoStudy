#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

bool is_phase(const vector<int>& A) {
    for(auto i = 1; i < A.size(); ++i) {
        if(A.size() % i) continue;
        bool ans = true;
        for(auto j = 0; j + i < A.size(); ++i) {
            if(A[j] != A[j + i]) {
                ans = false;
                break;
            }
        }

        if(ans) return true;
    }

    return false;
}

bool is_rotate(const vector<int>& A, const vector<int>& B) {    
    auto pi = vector<int>(B.size());
    for(auto i = 1, j = 0; i < B.size(); ++i)
    {
        while(j && B[i] != B[j]) j = pi[j-1];
        if(B[i] == B[j]) pi[i] = ++j;
    }

    vector<int> AA = A;
    AA.insert(AA.end(), A.begin(), A.end());
    for(auto i = 0, j = 0; i < AA.size(); ++i)
    {
        while(j && AA[i] != B[j]) j = pi[j-1];
        if(AA[i] == B[j]) {
            if(j == B.size() - 1) return true;
            else j++;
        }
    }

    return false;
}

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for(auto& x : A) cin >> x;
    for(auto& x : B) cin >> x;

    bool ans = true;
    if(k == 0) {
        ans = A == B;
    } else if (k == 1) {
        ans = A == B && is_phase(A) || A != B && is_rotate(A, B);
    } else if (n == 2) {
        if(k % 2 == 0) ans = A == B;
        else ans = A == B && is_phase(A) || A != B && is_rotate(A, B);
    } else {
        ans = is_rotate(A, B);
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";
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

