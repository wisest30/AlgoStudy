class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        auto possibleMerge = [&](auto a) {
            return a[0] <= target[0] && a[1] <= target[1] && a[2] <= target[2];
        };

        vector<int> merged(3);
        auto merge = [&](auto a) {
            for(auto i = 0; i < 3; ++i)
                merged[i] = max(merged[i], a[i]);
        };
               
        for(auto& t : triplets)
            if(possibleMerge(t))
                merge(t);
        
        return merged == target;
    }
};
