class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ret = 0;
        for(auto i = 0; i < n; ++i)
            for(auto j = i+1; j < n; ++j)
                if(colors[i] != colors[j])
                    ret = max(ret, j - i);
        
        return ret;
    }
};
