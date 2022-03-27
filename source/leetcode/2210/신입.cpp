class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> newNums;
        
        int before = -1;
        
        for(int num : nums)
        {
            if(before != num) newNums.push_back(num);
            before = num;
        }
        
        int cnt = 0;
        
        for(int i=1;i+1<newNums.size();i++)
        {
            if(newNums[i] > newNums[i+1] && newNums[i] > newNums[i-1]) cnt++;
            else if(newNums[i] < newNums[i+1] && newNums[i] < newNums[i-1]) cnt++;
        }
        
        return cnt;
    }
};
