class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size(), ret = 0, cur = 0;
        for(auto i = 1; cur + i <= n; ++i)
            ret++, cur += i;
        
        return ret;
    }
};
