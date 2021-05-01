class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ret = 0;
        
        for(auto i = 0; i < 32; ++i) {
            long long a = 0, b = 0;
            for(auto x : arr1) if(x & (1 << i)) a++;
            for(auto x : arr2) if(x & (1 << i)) b++;
            if(a * b % 2 == 1) ret |= 1 << i;
        }
        
        return ret;
    }
};
