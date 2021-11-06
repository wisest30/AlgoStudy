class Solution {
public:
    int smallestEqual(vector<int>& nums) {
    	int ret = -1;
    	for(int i = 0; i < nums.size(); i++){
    		if(nums[i] == i % 10 && ret == -1){
    			ret = i;
    		}
    	}
    	return ret;
    }
};
