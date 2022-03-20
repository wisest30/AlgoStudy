class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> A;
        for(auto num : nums)
            if(A.empty() || A.back() != num)
                A.push_back(num);
        
        int ret = 0;
        for(auto i = 1; i + 1 < A.size(); ++i)
            if(A[i] > A[i-1] && A[i] > A[i+1] || A[i] < A[i-1] && A[i] < A[i+1])
                ++ret;
        
        return ret;
    }
};
