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
    int maxSumMinProduct(vector<int>& nums) {        
        int n = nums.size();
        vector<int> L(n, -1), R(n, n);
        stack<int> s;
        for(auto i = 0; i < n; ++i) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                R[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(auto i = n-1; i >= 0; --i) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                L[s.top()] = i;
                s.pop();                
            }
            s.push(i);
        }
        
        auto ps = PSum(nums);
        long long ret = 0;
        for(auto i = 0; i < n; ++i) {
            long long candi = nums[i] * ps.get(L[i] + 1, R[i]);
            ret = max(ret, candi);
        }

        constexpr int MOD = 1e9 + 7;
        ret %= MOD;
        return ret;
    }
};
