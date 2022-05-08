class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        auto ret = INT_MAX;
        map<int, int> m;
        
        for(auto i = 0; i < cards.size(); ++i) {
            if(m.count(cards[i]))
                ret = min(ret, i - m[cards[i]] + 1);
            m[cards[i]] = i;
        }
        
        if(ret == INT_MAX)
            ret = -1;
        return ret;
    }
};