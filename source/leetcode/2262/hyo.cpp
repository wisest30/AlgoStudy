class Solution {
public:
    long long appealSum(string s) {
        long long ret = 0;
        map<char, int> m;
        for(auto i = 0; i < s.size(); ++i) {
            long long left = m.count(s[i]) ? i - m[s[i]] : i + 1;
            long long right = s.size() - i;
            ret += left * right;

            m[s[i]] = i;
        }
        
        return ret;
    }
};