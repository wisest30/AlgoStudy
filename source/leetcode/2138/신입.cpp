class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string cur = "";
        vector<string> ans;
        
        for(char ch : s)
        {
            cur += ch;
            if(cur.size() == k)
            {
                ans.push_back(cur);
                cur = "";
            }
        }
        
        while(!cur.empty() && cur.size() < k) cur += fill;
        if(!cur.empty()) ans.push_back(cur);
        
        return ans;
    }
};
