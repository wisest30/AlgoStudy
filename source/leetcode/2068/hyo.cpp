class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        for(auto c = 'a'; c <= 'z'; ++c) {
            int cnt1 = count(word1.begin(), word1.end(), c);
            int cnt2 = count(word2.begin(), word2.end(), c);
            if(abs(cnt1 - cnt2) > 3) return false;
        }
        
        return true;
    }
};
