class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        auto get_cnt = [](auto& w) {
            map<char, int> counter;
            for(auto c : w)
                counter[c]++;
            
            return counter;
        };
        
        vector<string> ret;
        for(auto& w : words)
            if(ret.empty() || get_cnt(ret.back()) != get_cnt(w))
                ret.push_back(w);
        
        return ret;
    }
};
