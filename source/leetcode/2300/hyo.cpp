class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ret;
        for(auto s : spells) {
            int l = -1, r = potions.size();
            while(l + 1 < r) {
                auto m = (l + r) / 2;
                if((long long)s * potions[m] >= success)
                    r = m;
                else
                    l = m;
            }
            ret.push_back((int)potions.size() - r);
        }
        
        return ret;
    }
};
