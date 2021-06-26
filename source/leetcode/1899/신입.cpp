class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cur = {1, 1, 1};
        
        for(auto &triplet : triplets)
        {
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2])
            {
                cur[0] = max(cur[0], triplet[0]);
                cur[1] = max(cur[1], triplet[1]);
                cur[2] = max(cur[2], triplet[2]);
            }
        }
        
        return cur == target;
    }
};
