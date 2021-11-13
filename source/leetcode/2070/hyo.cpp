class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        for(auto i = 1; i < n; ++i)
            items[i][1] = max(items[i][1], items[i-1][1]);
        
        vector<int> ret;
        for(auto q : queries) {
            auto p = lower_bound(items.begin(), items.end(), vector<int>{q+1, 0});
            ret.push_back(p == items.begin() ? 0 : (*prev(p))[1]);
        }
        
        return ret;
    }
};
