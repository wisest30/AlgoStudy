class Solution {
public:
    vector<int> thisWindowIdx[26];
    int remain[26];
    bool visit[26];
    
    int leftMostIdx;
    
    bool findMostLeftIdx(char ch)
    {
        if(remain[ch-'a']) return false;
        
        visit[ch-'a'] = true;    
        leftMostIdx = min(leftMostIdx, thisWindowIdx[ch-'a'].front());
        
        for(int i=0;i<26;i++)
        {
            if(ch - 'a' == i) continue;
            if(thisWindowIdx[i].empty()) continue;
            if(visit[i]) continue;
            
            if(thisWindowIdx[i].back() > thisWindowIdx[ch-'a'].front())
            {
                bool res = findMostLeftIdx(i+'a');
                if(!res) return res;
            }
        }
        
        return true;
    }
    
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;
        vector<int> remainCount(s.size(), 0);
        int count[26]{};
        
        memset(remain, 0x3f, sizeof(remain));
        
        for(char ch : s) count[ch-'a']++;
        
        for(int i=0;i<s.size();i++)
        {
            thisWindowIdx[s[i]-'a'].push_back(i);
            remain[s[i]-'a'] = --count[s[i]-'a'];
            
            memset(visit, 0, sizeof(visit));
            leftMostIdx = INT_MAX;
            
            bool res = findMostLeftIdx(s[i]);
            
            if(res) 
            {
                string temp;
                for(int j=leftMostIdx;j<=i;j++)
                {
                    temp += s[j];
                    remain[s[j]-'a'] = 0x3f3f3f3f;
                }
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
