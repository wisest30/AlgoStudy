class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i=0;
        int S=nums.size();
        int zero_temp=nums[0];
        while(1){
            int temp=nums[i];
            if(nums[i]==0){
                nums[i]=zero_temp;
                break;
            }
            nums[i]=nums[nums[i]];
            i=temp;
            
        }
        
        return nums;
    }
};
