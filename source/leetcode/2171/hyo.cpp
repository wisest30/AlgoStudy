class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        
        long long su = 0;
        long long max_val = 0;
        for(auto i = 0; i < n; ++i) {
            su += beans[i];
            max_val = max(max_val, (long long)(n - i) * beans[i]);
        }
        
        return su - max_val;
    }
};
