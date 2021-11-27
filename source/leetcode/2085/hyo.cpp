class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1, m2;
        for(auto& s : words1) m1[s]++;
        for(auto& s : words2) m2[s]++;
        
        int ret = 0;
        for(auto& p : m1)
            if(m1[p.first] == 1 && m2[p.first] == 1)
                ++ret;
        
        return ret;
    }
};
