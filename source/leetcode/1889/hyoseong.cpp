class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        
        sort(packages.begin(), packages.end());
        for(auto& B : boxes)
            sort(B.begin(), B.end());
        
        auto partialSum = vector<int64_t>(n + 1);
        for(auto i = 1; i <= n; ++i)
            partialSum[i] = partialSum[i-1] + packages[i-1];

        int64_t ret = INT64_MAX;
        for(auto& B : boxes) {
            if(B.back() < packages.back())
                continue;
            
            int64_t candi = 0, leftIdx = 0;
            for(int64_t boxSize : B) {
                auto rightIdx = upper_bound(packages.begin(), packages.end(), boxSize) - packages.begin();
                candi += boxSize * (rightIdx - leftIdx) - (partialSum[rightIdx] - partialSum[leftIdx]);
                leftIdx = rightIdx;
            }
            
            ret = min(ret, candi);
        }
        
        if(ret == INT64_MAX)
            return -1;

        return ret % 1000000007;
    }
};
