class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char, int> m;
        for(auto& w : words)
            for(auto c : w)
                m[c]++;
        
        for(auto& p : m)
            if(p.second % words.size())
                return false;
        return true;
    }
};
