class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26);
        for(auto c : s)
            ++cnt[c - 'a'];
        
        string ret;
        auto repeat = 0;
        for(auto i = 0; i < s.size(); ++i) {
            for(auto j = 25; j >= 0; --j) {
                char c = j + 'a';
                if(cnt[j] && !(repeat == repeatLimit && ret.back() == c)) {
                    if(!ret.empty() && ret.back() != c)
                        repeat = 1;
                    else
                        ++repeat;
                    
                    ret.push_back(c);
                    --cnt[j];
                    break;
                }
            }
        }
        
        return ret;
    }
};
