class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> A(n);
        for(auto i = 0; i < n; ++i)
            A[i] = abs(nums1[i] - nums2[i]);
        
        sort(A.begin(), A.end());
        
        int k = k1 + k2;
        int cnt = 1;
        long long ret = 0;
        while(!A.empty() && A.back()) {
            if(A.size() >= 2 && A[(int)A.size() - 2] == A.back()) {
                A.pop_back();
                ++cnt;
            }
            else if(cnt <= k) {
                k -= cnt;
                A[(int)A.size() - 1]--;
            } else {
                ret = (A.back() - 1) * (A.back() - 1) * k + A.back() * A.back() * (cnt - k);
                A.pop_back();
                break;
            }
        }
        
        for(auto a : A)
            ret += a * a;
        
        return ret;
    }
};
