#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int sum =0 ;
        int subsum= 0;
        
        sort(nums.begin(), nums.end());
        
        for(int elem : nums){
            sum += elem;
        }
        
        for(int i = nums.size()-1; i >=0; i--){
            subsum+= nums[i];
            ans.push_back(nums[i]);
            if( subsum > sum - subsum)
                break;
        }
        return ans;
    }
};
