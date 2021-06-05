class Solution {
public:
    int max_len(const string& s, char x) {
        int ret = 0, cnt = 0;
        for(auto c : s) {
            cnt = c == x ? cnt + 1 : 0;
            ret = max(ret, cnt);
        }
        return ret;
    }
    
    bool checkZeroOnes(string s) {
        return max_len(s, '1') > max_len(s, '0');
    }
};
