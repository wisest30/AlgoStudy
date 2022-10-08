class Solution {
public:
    bool equalFrequency(string word) {
        for(auto i = 0; i < word.size(); ++i) {
            map<int, int> m;
            for(auto j = 0; j < word.size(); ++j)
                if(i != j) m[word[j]]++;
            
            set<int> s;
            for(auto& p : m) s.insert(p.second);
            if(s.size() <= 1) return true;
        }
        
        return false;
    }
};
