class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> answer;
        
        for(int i=0;i<nums.size();++i)
        {
            if(index[i] == answer.size()) answer.push_back(nums[i]);
            else
            {
                answer.push_back(0);
                for(int j=(int)answer.size()-1;j>index[i];--j) answer[j] = answer[j-1];
                answer[index[i]] = nums[i];
            }
        }
        
        return answer;
    }
};
