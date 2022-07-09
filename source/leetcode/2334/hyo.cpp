class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> l(n, -1), r(n, n);
        vector<int> st;
        for(auto i = 0; i < n; ++i) {
            while(!st.empty() && nums[st.back()] > nums[i]) {
                r[st.back()] = i;
                st.pop_back();
            }
            
            if(!st.empty())
                l[i] = st.back();

            st.push_back(i);
        }
        
        for(auto i = 0; i < n; ++i) {
            long long k = r[i] - (l[i] + 1);
            if(nums[i] * k > threshold)
                return k;
        }
        
        return -1;
    }
};
