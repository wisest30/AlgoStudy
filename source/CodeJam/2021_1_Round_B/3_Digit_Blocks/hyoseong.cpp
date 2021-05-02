#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

int input() {
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
}

void output(int a) {
    cout << a << endl;
}

int n, b;
ll p;
vector<int> A;
bool to_top() {
    for(auto i = 0; i < n; ++i) {
        if(A[i] != b - 1) continue;
        output(i+1);
        A[i]++;
        return true;
    }

    return false;
}

bool to_second() {
    for(auto i = 0; i < n; ++i) {
        if(A[i] != b - 2) continue;
        output(i+1);
        A[i]++;
        return true;
    }

    return false;
}

bool to_high() {
    int max_val = -1;
    int max_idx = -1;
    for(auto i = 0; i < n; ++i) {
        if(A[i] == b) continue;
        if(A[i] > max_val)
            max_val = A[i], max_idx = i;
    }

    A[max_idx]++;
    output(max_idx + 1);
    return true;
}

bool to_low() {
    auto i = min_element(A.begin(), A.end()) - A.begin();
    output(i+1);
    A[i]++;
    return true;
}

bool to_below_second() {
    for(auto i = 0; i < n; ++i) {
        if(A[i] >= b - 2) continue;
        output(i+1);
        A[i]++;
        return true;
    }

    return false;
}

void solve(int TestCase) {
    A = vector<int>(n);
    for(auto i = 0; i < n * b; ++i) {
        auto x = input();
        if(x == 9) {
            to_high();
        }
        else if (x >= 6) {
            if(to_second()) continue;
            if(to_below_second()) continue;
            to_top();
        }
        else {
            if(to_below_second()) continue;
            to_low();
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t >> n >> b >> p;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }

    input();
}
