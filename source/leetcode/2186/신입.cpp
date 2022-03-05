class Solution {
public:
    int minSteps(string s, string t) {
        int sCnt[26]{};
        int tCnt[26]{};
        
        for(char ch : s) sCnt[ch-'a']++;
        for(char ch : t) tCnt[ch-'a']++;
        
        int ans = 0;
        
        for(int i=0;i<26;i++)
        {
            int target = max(sCnt[i], tCnt[i]);
            ans += target - sCnt[i] + target - tCnt[i];
        }
        
        return ans;
    }
};
