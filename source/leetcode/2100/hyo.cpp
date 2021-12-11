class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n), right(n);
        for(auto i = 1; i < n; ++i) {
            if(security[i] <= security[i-1])
                left[i] = left[i-1] + 1;
        }
        
        for(auto i = n-2; i >= 0; --i) {
            if(security[i] <= security[i+1])
                right[i] = right[i+1] + 1;
        }
        
        vector<int> ret;
        for(auto i = 0; i < n; ++i) {
            if(left[i] >= time && right[i] >= time)
                ret.push_back(i);
        }
        
        return ret;
    }
};
