class Solution {
public:
    int countVowelSubstrings(string word) {        
        auto idx = [](auto c) {
            if(c == 'a') return 0;
            else if(c == 'e') return 1;
            else if(c == 'i') return 2;
            else if(c == 'o') return 3;
            else if(c == 'u') return 4;
            else return 5;
        };

        int ret = 0, n = word.size();
        for(auto l = 0; l < n; ++l) {
            int cnt[6] = {0};
            for(auto r = l+1; r <= n; ++r) {
                cnt[idx(word[r-1])]++;
                
                if(cnt[0] && cnt[1] && cnt[2] && cnt[3] && cnt[4] && !cnt[5])
                    ++ret;
            }
        }
        
        return ret;
    }
};
