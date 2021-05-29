class FindSumPairs {
public:
    vector<int> nums1, nums2;
    map<int, int> M;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto x : nums2) M[x]++;
    }
    
    void add(int index, int val) {
        M[nums2[index]]--;
        nums2[index] += val;
        M[nums2[index]]++;
    }
    
    int count(int tot) {
        int ret = 0;
        for(auto x : nums1) {
            auto y = tot - x;
            if(M.count(y))
                ret += M[y];
        }
        return ret;
    }
};
