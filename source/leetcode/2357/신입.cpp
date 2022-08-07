class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> positiveNumSet;
        for(int num : nums)
        {
            if(num) positiveNumSet.insert(num);
        }
        return positiveNumSet.size();
    }
};
