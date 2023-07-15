#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int query(int x, int y) {
    cout << "? " << (x + 1) << " " << (y + 1) << endl;
    int ret;
    cin >> ret;
    if(ret == -1) exit(0);
    return ret;
}

void answer(int x) {
    cout << "! " << (x + 1) << endl;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    if(n == -1) exit(0);
    deque<int> A(1 << n);
    iota(A.begin(), A.end(), 0);

    while(A.size() >= 4) {
        auto r = query(A[0], A[2]);
        if(r == 0) {
            r = query(A[1], A[3]);
            if(r == 1) A.push_back(A[1]);
            else A.push_back(A[3]);
        } else if(r == 1) {
            r = query(A[0], A[3]);
            if(r == 1) A.push_back(A[0]);
            else A.push_back(A[3]);
        } else if(r == 2) {
            r = query(A[1], A[2]);
            if(r == 1) A.push_back(A[1]);
            else A.push_back(A[2]);
        }

        A.pop_front();
        A.pop_front();
        A.pop_front();
        A.pop_front();
    }

    if(A.size() == 2) {
        auto r = query(A[0], A[1]);
        if(r == 1) A.push_back(A[0]);
        else A.push_back(A[1]);

        A.pop_front();
        A.pop_front();
    }

    answer(A[0]);
}
 
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
