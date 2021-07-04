#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, m;
vector<int> A;
string s;

int getCollisionTime(int x0, char d0, int x1, char d1) {
    if(x0 == x1) return 0;
    if(x0 > x1)
        return getCollisionTime(x1, d1, x0, d0);
    
    if(x0 % 2 != x1 % 2)
        return -1;
    
    if(d0 == 'R' && d1 == 'L')
        return (x1 - x0) / 2;
    else if(d0 == 'R' && d1 == 'R') {
        auto t = m - x1;
        return t + getCollisionTime(x0 + t, 'R', m, 'L');
    }
    else if(d0 == 'L' && d1 == 'L') {
        auto t = x0;
        return t + getCollisionTime(0, 'R', x1 - t, 'L');
    }
    else {
        auto t0 = m - x1;
        auto t1 = x0;
        if(t0 < t1) {
            auto t = m - x1;
            return t + getCollisionTime(x0 - t, 'L', m, 'L');
        }
        else {
            auto t = x0;
            return t + getCollisionTime(0, 'R', x1 + t, 'R');
        }
    }

    return -1;
}

void solve(int TestCase) {
    cin >> n >> m;
    A.resize(n);
    s.clear();
    for(auto& x : A) cin >> x;
    for(auto i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](auto l, auto r) {
        return A[l] < A[r];
    });

    vector<int> ret(n, -1);
    vector<int> stack_[2];
    for(auto i : order) {
        auto& st = stack_[A[i] % 2];
        if(!st.empty() && s[st.back()] == 'R' && s[i] == 'L') {
            auto t = getCollisionTime(A[st.back()], 'R', A[i], 'L');

            ret[st.back()] = ret[i] = t;
            st.pop_back();
            continue;
        }

        st.push_back(i);
    }

    for(auto i = 0; i < 2; ++i) {
        auto& st = stack_[i];
        while(st.size() >= 2 && s[st[st.size() - 2]] == 'R') {
            auto i0 = st[st.size() - 2];
            auto i1 = st.back();
            st.pop_back();
            st.pop_back();

            auto t = getCollisionTime(A[i0], s[i0], A[i1], s[i1]);
            ret[i0] = ret[i1] = t;
        }

        for(auto j = 0; j + 1 < st.size(); j += 2) {
            auto i0 = st[j];
            auto i1 = st[j+1];
            auto t = getCollisionTime(A[i0], s[i0], A[i1], s[i1]);
            ret[i0] = ret[i1] = t;
        }
    }

    for(auto x : ret) cout << x << " ";
    cout << endl;
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
