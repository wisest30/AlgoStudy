class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int targetCnt[26]{};
        int sCnt[26]{};
        
        for(char ch : s) sCnt[ch-'a']++;
        for(char ch : target) targetCnt[ch-'a']++;
        
        int ans = INT_MAX;
        
        for(int i=0;i<26;i++)
        {
            if(targetCnt[i] == 0) continue;
            ans = min(ans, sCnt[i]/targetCnt[i]);
        }
        
        return ans;
    }
};
