#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<string> A, B;
void init() {
    for(auto subset = 0; subset < (1 << 10); ++subset) {
        string s;
        for(auto i = 0; i < 10; ++i) {
            if(subset & (1 << i)) s.push_back('.');
            else s.push_back('-');
        }

        if(s[0] == '.') A.push_back(s);
        else B.push_back(s);
    }
}

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto& W = s.front() == '.' ? B : A;
    cout << '\n';
    for(auto i = 0; i < n-1; ++i)
        cout << W[i] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    init();
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}


