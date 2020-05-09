class Solution {
public:
    int maxScore(string s) {
        int zero_count = 0;
        int one_count = 0;
        
       for(int i=0;i<s.size();++i)
       {
           if(s[i] == '1') one_count++;
       }
        
        int ans = 0;
        
        for(int i=0;i<(int)s.size() - 1;++i)
        {
            if(s[i] == '0') zero_count++;
            if(s[i] == '1') one_count--;
            
            if(zero_count + one_count > ans) ans = zero_count + one_count;
        }
        
        return ans;
    }
};
