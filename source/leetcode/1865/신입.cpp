class FindSumPairs {
public:
    map<int, int> nums1Map;
    map<int, int> nums2Map;
    vector<int> nums2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int num : nums1) nums1Map[num]++;
        for(int num : nums2) nums2Map[num]++;
        this->nums2 = nums2;
    }
    
    void add(int index, int val) {
        nums2Map[nums2[index]]--;
        if(nums2Map[nums2[index]] == 0) nums2Map.erase(nums2[index]);
        nums2Map[nums2[index]+val]++;
        nums2[index] += val;
    }
    
    int count(int tot) {
        int ret = 0;
        
        for(auto it = nums1Map.begin();it!=nums1Map.end();it++)
        {
            auto it2 = nums2Map.lower_bound(tot-it->first);
            if(it2 != nums2Map.end() && it->first + it2->first == tot) ret += it->second * it2->second;
        }
        
        return ret;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
