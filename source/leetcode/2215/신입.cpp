class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1Set;
        set<int> nums2Set;
        
        for(int num : nums1) nums1Set.insert(num);
        for(int num : nums2) nums2Set.insert(num);
        
        vector<vector<int>> answer;
        
        vector<int> answerZero;
        vector<int> answerOne;
        
        for(auto it = nums1Set.begin(); it != nums1Set.end() ; it++)
        {
            if(nums2Set.find(*it) == nums2Set.end()) answerZero.push_back(*it); 
        }
        
        answer.push_back(answerZero);
        
        for(auto it = nums2Set.begin(); it != nums2Set.end() ; it++)
        {
            if(nums1Set.find(*it) == nums1Set.end()) answerOne.push_back(*it);
        }
        
        answer.push_back(answerOne);
        
        return answer;
    }
};
