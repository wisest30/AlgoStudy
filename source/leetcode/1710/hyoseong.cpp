class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& x, auto& y) {
            return x[1] > y[1];
        });
        
        int ret = 0, remain = truckSize;
        for(auto& x : boxTypes) {
            if(remain == 0) break;
            
            int num = x[0], unit = x[1];
            int p = min(remain, num);
            remain -= p;
            ret += p * unit;
        }
        
        return ret;
    }
};
