#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<int> A;
int n, q;

int query(int a1, int a2, int a3) {
    cout << a1 << " " << a2 << " " << a3 << endl;

    int x;
    cin >> x;
    if(x == -1) exit(0);
    else return x;
}

int ans() {
    for(auto x : A) cout << x << " ";
    cout << endl;

    int x;
    cin >> x;
    if(x == -1) exit(0);
    else return x;
}

void recur(int l, int r) {
    if(r - l <= 1) return;

    if(l > 0) {
        int x = query(A[l-1], A[l], A[l+1]);
        if(x == A[l+1])
            swap(A[l], A[l+1]);
    }
    else if(r < n) {
        int x = query(A[l], A[l+1], A[r]);
        if(x == A[l])
            swap(A[l], A[l+1]);
    }

    if(r - l == 2) return;

    vector<int> L, M, R;
    for(auto i = l+2; i < r; ++i) {
        int x = query(A[l], A[l+1], A[i]);
        if(x == A[l]) L.push_back(A[i]);
        else if(x == A[l+1]) R.push_back(A[i]);
        else M.push_back(A[i]);
    }

    int a = A[l], b = A[l+1];
    int i = l, a_idx = -1, b_idx = -1;

    for(auto j = 0; j < L.size(); ++j) A[i++] = L[j];
    a_idx = i;
    A[i++] = a;

    for(auto j = 0; j < M.size(); ++j) A[i++] = M[j];
    b_idx = i;
    A[i++] = b;

    for(auto j = 0; j < R.size(); ++j) A[i++] = R[j];

    recur(l, a_idx);
    recur(a_idx + 1, b_idx);
    recur(b_idx + 1, r);
}

void solve(int TestCase) {
    A = vector<int>(n);
    iota(A.begin(), A.end(), 1);
    recur(0, n);
    ans();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    cin >> n >> q;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
