class Solution {
public:
    int divisorSubstrings(int num, int k) {
        auto s = to_string(num);
        auto ret = 0;
        for(auto i = 0; i + k <= s.size(); ++i) {
            int d = stoi(s.substr(i, k));
            if(d && num % d == 0)
                ++ret;
        }
        
        return ret;
    }
};
