class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;

        map<int, int> c0, c1;
        for(auto i = 0; i < n; ++i)
            i % 2 ? c0[nums[i]]++ : c1[nums[i]]++;
        
        vector<pair<int, int>> p0(c0.begin(), c0.end()), p1(c1.begin(), c1.end());
        sort(p0.begin(), p0.end(), [](auto x, auto y) { return x.second > y.second; });
        sort(p1.begin(), p1.end(), [](auto x, auto y) { return x.second > y.second; });
        
        int ret = n - max(p0[0].second, p1[0].second);
        for(auto i = 0; i < min(2, (int)p0.size()); ++i)
            for(auto j = 0; j < min(2, (int)p1.size()); ++j)
                if(p0[i].first != p1[j].first)
                    ret = min(ret, n - p0[i].second - p1[j].second);

        return ret;
    }
};
