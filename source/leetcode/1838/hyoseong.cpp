class Solution {
    class PSum {
        using T = long long;
        vector<T> ps;

    public :
        template<typename U>
        PSum(const vector<U>& A)
        : ps(A.size() + 1)
        {
            for(auto i = 1; i < ps.size(); ++i)
                ps[i] = ps[i-1] + A[i-1];
        }

        T get(int left, int right) {
            return ps[right] - ps[left];
        }
    };

public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        PSum ps(nums);
        
        int n = nums.size();
        int ret = 1;
        for(auto i = 0; i < n; ++i) {
            int l = -1, r = i;
            while(l + 1 < r) {
                auto m = (l+r) / 2;
                if((long long)(i - m) * nums[i] - ps.get(m, i) <= k)
                    r = m;
                else
                    l = m;
            }
            ret = max(ret, i + 1 - r);
        }
        return ret;
    }
};
