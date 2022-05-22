class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](auto l, auto r) {
            return capacity[l] - rocks[l] < capacity[r] - rocks[r];
        });
        
        int ret = 0;
        for(auto i : order) {
            if(capacity[i] - rocks[i] <= additionalRocks) {
                ++ret;
                additionalRocks -= capacity[i] - rocks[i];
            } else {
                break;
            }
        }
        
        return ret;
    }
};
