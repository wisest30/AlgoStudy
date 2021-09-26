class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n =nums.size();
        vector<int>maxArr(nums.size());
        vector<int>minArr(nums.size());
        maxArr[0]=nums[0];
        minArr[n-1]=nums[n-1];
        int ret;
        for(int i=1;i<n;i++){
            maxArr[i]=max(maxArr[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            minArr[i]=min(minArr[i+1],nums[i]);
        }
        for(int i=1;i<n-1;i++){
            if(maxArr[i-1]<nums[i] && nums[i] < minArr[i+1])ret+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])ret++;
        }
        return ret;
        
        
        
    }
};
