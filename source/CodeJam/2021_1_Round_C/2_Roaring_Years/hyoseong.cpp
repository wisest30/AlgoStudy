#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

using i128 = __int128_t;
string to_str(i128 x){
	if(x == 0) return "0";

	string ret = "";
	while(x){
        ret.push_back('0' + int(x % 10));
		x /= 10;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

i128 to_i128(const string& x) {
    i128 ret = 0;
    for(auto c : x)
        ret = ret * 10 + (c - '0');
    return ret;    
}

void solve(int TestCase) {
    string s;
    cin >> s;

    i128 y;
    y = to_i128(s);

    i128 ret = numeric_limits<ll>::max();
    for(auto i = 1; i <= s.size(); ++i) {
        vector<i128> A;
        A.push_back(stoll(s.substr(0, i)));
        A.push_back(A.back() + 1);

        i128 a = 1;
        for(auto j = 0; j < i-1; ++j) a *= 10;
        A.push_back(a);

        a = 9;
        for(auto j = 0; j < i-1; ++j) a = a * 10 + 9;
        for(auto j = 0; j < 20; ++j)
            if(a - j > 0)
                A.push_back(a - j);

        for(auto start : A) {
            i128 cur = start;
            i128 candi = start;

            int add_cnt = 0;
            while(candi <= y || add_cnt == 0) {
                cur++;
                add_cnt++;
                candi = to_i128(to_str(candi) + to_str(cur));
            }

            ret = min(ret, candi);
        }
    }

    cout << to_str(ret) << endl;
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
