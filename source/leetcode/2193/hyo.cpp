class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size(), ret = 0;
        while(s.size() > 1) {
            vector<int> first(26, -1), last(26);
            int min_idx = -1, min_cost = INT_MAX;
            for(auto i = 0; i < s.size(); ++i) {
                auto idx = s[i] - 'a';
                
                if(first[idx] == -1)
                    first[idx] = i;
                
                last[idx] = i;
                
                if(first[idx] != last[idx]) {
                    auto cost = first[idx] + (int)s.size() - 1 - last[idx];
                    if(cost < min_cost) {
                        min_idx = s[i] - 'a';
                        min_cost = cost;
                    }
                }
            }

            ret += min_cost;
            s.erase(s.begin() + last[min_idx]);
            s.erase(s.begin() + first[min_idx]);
        }
        
        return ret;
    }
};
