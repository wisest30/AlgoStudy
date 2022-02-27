class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26]{};
        string ans;
        
        for(char ch : s)
        {
            cnt[ch-'a']++;
        }
        
        int repeat = 0;
        
        while(true)
        {
            int beforeSz = ans.size();
            
            for(int i=25;i>=0;--i)
            {
                if(cnt[i] > 0 && repeat < repeatLimit && !ans.empty() && ans.back() == i+'a')
                {
                    cnt[i]--;
                    repeat++;
                    ans += i+'a';
                    break;
                }
                else if(cnt[i] > 0 && (ans.empty() || ans.back() != i+'a'))
                {
                    cnt[i]--;
                    repeat = 1;
                    ans += i+'a';
                    break;
                }
            }
            
            if(beforeSz == ans.size()) break;
        }
        
        return ans;
    }
};
