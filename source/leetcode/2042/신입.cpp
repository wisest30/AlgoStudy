class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> nums;
        int num = 0;
        
        s.push_back(' ');
        
        for(char ch : s)
        {
            if(ch >= '0' && ch <= '9') num = num * 10 + ch - '0';
            else if(num)
            {
                nums.push_back(num);
                num = 0;
            }
        }
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <= nums[i-1]) return false;
        }
        
        return true;
    }
};
