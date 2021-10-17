class Solution {
public:
    void makeUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
    }
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int, int> numMap;
        
        makeUnique(nums1);
        makeUnique(nums2);
        makeUnique(nums3);
        
        for(int num : nums1) numMap[num]++;
        for(int num : nums2) numMap[num]++;
        for(int num : nums3) numMap[num]++;
        
        vector<int> ans;
        
        for(auto [k, v] : numMap)
        {
            if(v >= 2) ans.push_back(k);
        }
        
        return ans;
    }
};
