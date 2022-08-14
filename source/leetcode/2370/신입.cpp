class Solution {
public:
    int longestIdealString(string s, int k) {
       int longest[26]{};
        
        for(char ch : s)
        {
            int temp = 0;
            
            for(int i=max(0, ch-'a'-k);i<=min(25, ch-'a'+k);i++)
            {
                temp = max(temp, longest[i]+1);
            }
            
            longest[ch-'a'] = temp;
        }
        
        int mx = 0;
        
        for(int i=0;i<26;i++) mx = max(mx, longest[i]);
        
        return mx;
    }
};
