class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        set<pair<int, int>> range;
        multiset<int> ms;
        for(auto i = 0, left = 0; i < s.size(); ++i) {
            if(i + 1 < s.size() && s[i] == s[i + 1])
                continue;
            
            range.insert({left, i + 1});
            ms.insert(i + 1 - left);
            left = i + 1;
        }
        
        auto insert = [&](pair<int, int> p) {
            range.insert(p);
            ms.insert(p.second - p.first);
        };

        auto erase = [&](pair<int, int> p) {
            range.erase(p);
            ms.erase(ms.find(p.second - p.first));
        };
        
        vector<int> ret;
        for(auto k = 0; k < queryCharacters.size(); ++k) {
            auto c = queryCharacters[k];
            auto i = queryIndices[k];
            
            auto p = *prev(range.lower_bound(make_pair(i, INT_MAX)));
            erase(p);
            
            if(p.first < i)
                insert(make_pair(p.first, i));
            if(p.second > i + 1)
                insert(make_pair(i + 1, p.second));
            
            auto new_p = make_pair(i, i+1);
            if(i && s[i-1] == c) {
                auto p = *prev(range.lower_bound(make_pair(i, 0)));
                erase(p);
                
                new_p.first = p.first;
            }
            if(i + 1 < s.size() && s[i+1] == c) {
                auto p = *range.lower_bound(make_pair(i, 0));
                erase(p);
                
                new_p.second = p.second;
            }
            
            insert(new_p);
            
            ret.push_back(*ms.rbegin());
            s[i] = c;
        }
        
        return ret;
    }
};
