class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ret = 0;
        
        for(auto i = 0; i < 32; ++i) {
            int a = 0, b = 0;
            for(auto x : arr1) if(x & (1 << i)) a ^= 1;
            for(auto x : arr2) if(x & (1 << i)) b ^= 1;
            if(a && b) ret |= 1 << i;
        }
        
        return ret;
    }
};
