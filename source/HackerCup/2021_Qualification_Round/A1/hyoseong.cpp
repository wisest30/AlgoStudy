#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
void solve(int TestCase) {
    string s;
    cin >> s;

    int ret = INT_MAX;
    for(char to = 'A'; to <= 'Z'; ++to) {
        int candi = 0;
        for(auto c : s) {
            if(c == to) continue;
            candi += isVowel(c) == isVowel(to) ? 2 : 1;
        }

        ret = min(ret, candi);
    }

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
