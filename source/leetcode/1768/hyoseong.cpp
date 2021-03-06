class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret;
        for(auto i = 0; i < max(word1.size(), word2.size()); ++i) {
            if(i < word1.size()) ret.push_back(word1[i]);
            if(i < word2.size()) ret.push_back(word2[i]);
        }
        return ret;
    }
};
