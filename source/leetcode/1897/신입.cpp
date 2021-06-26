class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26]{};
        
        for(string &word : words)
        {
            for(char ch : word)
            {
                cnt[ch-'a']++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(cnt[i]%(int)words.size()) return false;
        }
        
        return true;
    }
};
