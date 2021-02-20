class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string ret;
        while(i < word1.size() || j < word2.size())
            word1.substr(i) > word2.substr(j) ? ret.push_back(word1[i++]) : ret.push_back(word2[j++]);

        return ret;
    }
};
