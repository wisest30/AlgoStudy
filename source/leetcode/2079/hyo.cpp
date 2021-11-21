class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int c = capacity;
        int ret = 0;
        for(auto i = 0; i < n; ++i) {
            if(c >= plants[i]) {
                c -= plants[i];
                ret++;
            } else {
                ret += i * 2;
                c = capacity;
                --i;
            }
        }
        
        return ret;
    }
};
