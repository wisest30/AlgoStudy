class Solution {
public:
    bool f(const string& s, unsigned long long start) {
        if(s.empty())
            return true;
        
        if(start == 0) {
            for(auto c : s)
                if(c != '0')
                    return false;
            
            return true;
        }
        
        int i = 0;
        unsigned long long cur = 0;
        for(i = 0; i < s.size(); ++i) {
            cur = cur * 10 + s[i] - '0';
            if(cur == start) break;
            else if(cur > start) return false;
        }
        
        if(cur < start) return false;
        
        return f(s.substr(i+1), start - 1);
    }
    
    bool splitString(string s) {
        if(f(s, 0))
            return false;
        
        for(auto i = 1; i < s.size(); ++i) {
            unsigned long long start = stoull(s.substr(0, i));
            if(f(s, start))
                return true;
        }
        
        return false;
    }
};
