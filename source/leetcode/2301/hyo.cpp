class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> m;
        for(auto& p : mappings)
            m[p[0]].insert(p[1]);
        
        int i = 0, j = 0;
        while(i < s.size() && j < sub.size()) {            
            if(s[i] == sub[j] || m[sub[j]].count(s[i]))
                ++i, ++j;
            else {
                i -= j - 1;
                j = 0;
            }
        }

        return j == sub.size();
    }
};
