
#define MOD 1000000007
typedef long long ll;
class Solution {
public:
    string longestPrefix(string s) {
        ll preh = 0, sufh = 0;
        ll exp = 1;
        int len = 0;
        for(int i=0, j=s.size()-1; i<s.size()-1; i++, j--) {
            preh = (preh*26+(s[i]-'a'))%MOD;
            sufh = (sufh+exp*(s[j]-'a'))%MOD;
            exp = (exp*26)%MOD;
            if(preh==sufh) {
                len = i+1;
            }
        }
        return s.substr(0, len);
    }
};
