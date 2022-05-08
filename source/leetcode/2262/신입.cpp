typedef long long ll;

class Solution {
public:
    long long appealSum(string s) {
        ll ans = 0;
        vector<int> idxes[26];
        
        for(int i=0;i<s.size();i++) idxes[s[i]-'a'].push_back(i);
        for(int i=0;i<26;i++)
        {
            int prv = -1;
            
            for(int j=0;j<idxes[i].size();j++) 
            {
                ans += 1LL * (idxes[i][j] - prv) * (s.size() - idxes[i][j]);    
                prv = idxes[i][j];
            }
        }
        
        return ans;
    }
};
