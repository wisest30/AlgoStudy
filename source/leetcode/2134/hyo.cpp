class Solution {
public:
    class PSum {
        vector<int> ps;
    public :
        PSum(const vector<int>& A)
        : ps(A.size() + 1)
        { for(auto i = 1; i < ps.size(); ++i) ps[i] = ps[i-1] + A[i-1]; }
        int get(int left, int right) { return ps[right] - ps[left]; }
    };
    
    int minSwaps(vector<int>& nums) {
        PSum ps(nums);
        int n = nums.size(), su = ps.get(0, n), ret = INT_MAX;
        for(auto i = 0; i < n; ++i) ret = min(ret, su - ps.get(i, min(i + su, n)) - ps.get(0, max(0, i + su - n)));
        return ret;
    }
};
