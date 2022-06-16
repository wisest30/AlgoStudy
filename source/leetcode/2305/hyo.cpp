class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size(), max_mask = pow(k, n-1), ret = INT_MAX;
        for(auto subset = 0; subset < max_mask; ++subset) {
            vector<int> A(k);
            A[0] = cookies[0];
            for(auto s = subset, i = 1; i < n; ++i, s /= k)
                A[s % k] += cookies[i];
            
            ret = min(ret, *max_element(A.begin(), A.end()));
        }
        
        return ret;
    }
};
