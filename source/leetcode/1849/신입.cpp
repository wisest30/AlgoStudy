typedef unsigned long long ull;

class Solution {
public:
    bool find(string &s, int idx, ull targetNum)
    {
        if(idx == s.size()) return true;
        
        printf("%llu\n", targetNum);
        
        ull cur = 0;
        
        for(;idx<s.size();idx++)
        {
            cur = cur * 10 + s[idx] - '0';
            if(cur == targetNum) 
            {
                if(targetNum == 0) return find(s, idx+1, targetNum);
                return find(s, idx+1, targetNum-1);
            }
            else if(cur > targetNum) return false;
        }
        
        return false;
    }
    
    bool splitString(string s) {
        ull stNum = 0;
        
        for(int i=0;i<(int)s.size()-1;i++)
        {
            stNum = stNum * 10 + s[i] - '0';
            if(find(s, i+1, stNum-1)) return true;
        }
        
        return false;
    }
};
