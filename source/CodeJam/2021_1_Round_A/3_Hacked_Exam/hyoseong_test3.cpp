#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
using i128 = __int128_t;
//using i128 = ll;

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

i128 gcd(i128 a, i128 b){
	while(a > 0){
		b %= a;
		swap(a, b);
	}
	return b;
}

class Combination {
    using T = i128;
    T MOD;
    vector<vector<T>> A;
public :
    Combination(int n, T MOD = 0)
    : A(n+1, vector<T>(n+1)), MOD(MOD) {
        assert(n > 0);
        A[1][0] = A[1][1] = 1;
        for(auto i = 2; i <= n; ++i) {
            A[i][0] = 1;
            for(auto j = 1; j <= n; ++j) {
                A[i][j] = A[i-1][j-1] + A[i-1][j];
                if(MOD) A[i][j] %= MOD;
            }
        }
    }

    T nCr(int n, int r) {
        assert(n < A.size());
        assert(r <= n);
        if(n == 0 && r == 0) return 1;
        return A[n][r];
    }
};

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    vector<pair<string, int>> A(n);
    for(auto& x : A) cin >> x.first >> x.second;

    while(n < 3) n++, A.push_back(A[0]);

    i128 T00 = 0, T01 = 0, T10 = 0, T11 = 0;
    vector<int> tp(q);
    for(auto i = 0; i < q; ++i) {
        auto c0 = A[0].first[i];
        auto c1 = A[1].first[i];
        auto c2 = A[2].first[i];

        if(c0 != c1 && c0 != c2) T00++, tp[i] = 0;
        else if(c0 != c1 && c0 == c2) T01++, tp[i] = 1;
        else if(c0 == c1 && c0 != c2) T10++, tp[i] = 2;
        else T11++, tp[i] = 3;
    }

    Combination comb(q);

    i128 total = 0;
    i128 c00 = 0, c01 = 0, c10 = 0, c11 = 0;
    for(i128 t00 = 0; t00 <= T00; ++t00) {
        for(i128 t01 = 0; t01 <= T01; ++t01) {
            for(i128 t10 = 0; t10 <= T10; ++t10) {
                i128 t11 = (i128)A[0].second - t00 - t01 - t10;

                if(t11 < 0 || t11 > T11) continue;
                if(T00 - t00 + T01 - t01 + t10 + t11 != A[1].second) continue;
                if(T00 - t00 + t01 + T10 - t10 + t11 != A[2].second) continue;

                total += comb.nCr(T00, t00) * comb.nCr(T01, t01) * comb.nCr(T10, t10)
                            * comb.nCr(T11, t11);
                
                if(t00 > 0)
                    c00 += comb.nCr(T00 - 1, t00 - 1) * comb.nCr(T01, t01) * comb.nCr(T10, t10)
                           * comb.nCr(T11, t11);
                if(t01 > 0)
                    c01 += comb.nCr(T00, t00) * comb.nCr(T01-1, t01-1) * comb.nCr(T10, t10)
                           * comb.nCr(T11, t11);
                if(t10 > 0)
                    c10 += comb.nCr(T00, t00) * comb.nCr(T01, t01) * comb.nCr(T10-1, t10-1)
                           * comb.nCr(T11, t11);
                if(t11 > 0)
                    c11 += comb.nCr(T00, t00) * comb.nCr(T01, t01) * comb.nCr(T10, t10)
                           * comb.nCr(T11-1, t11-1);    
            }
        }
    }

    string ret0;
    i128 ret1 = 0, ret2 = total;
    for(auto i = 0; i < q; ++i) {
        auto c = A[0].first[i];
        auto r = c == 'T' ? 'F' : 'T';
        if(tp[i] == 0) {
            if(c00 * 2 >= total) ret0.push_back(c), ret1 += c00;
            else ret0.push_back(r), ret1 += total - c00;
        }
        else if(tp[i] == 1) {
            if(c01 * 2 >= total) ret0.push_back(c), ret1 += c01;
            else ret0.push_back(r), ret1 += total - c01;
        }
        else if(tp[i] == 2) {
            if(c10 * 2 >= total) ret0.push_back(c), ret1 += c10;
            else ret0.push_back(r), ret1 += total - c10;
        }
        else {
            if(c11 * 2 >= total) ret0.push_back(c), ret1 += c11;
            else ret0.push_back(r), ret1 += total - c11;
        }
    }

    auto g = gcd(ret1, ret2);

    ret1 /= g;
    ret2 /= g;

    cout << ret0 << " " << to_str(ret1) << "/" << to_str(ret2) << endl;
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
