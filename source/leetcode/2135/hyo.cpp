class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        auto stomask = [](auto& s) {
            int mask = 0;
            for(auto c : s) mask |= 1 << (c - 'a');
            return mask;
        };
        set<int> start;
        for(auto& s : startWords) start.insert(stomask(s));
        int ret = 0;
        for(auto& s : targetWords) {
            auto mask = stomask(s);
            auto add = false;
            for(auto i = 0; i < 26; ++i) add |= (mask & (1 << i)) && start.count(mask - (1 << i));
            ret += add;
        }
        return ret;
    }
};
