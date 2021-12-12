class Solution {
public:
    int cnt[10];
    
    bool valid(int num)
    {
        int numCnt[10]{};
        
        while(num)
        {
            numCnt[num%10]++;
            num/=10;
        }
        
        for(int i=0;i<10;i++)
        {
            if(cnt[i] < numCnt[i]) return false;
        }
        
        return true;
    }
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        for(int num : digits) cnt[num]++;
        
        vector<int> ans;
        
        for(int i=100;i<=998;i+=2)
        {
            if(valid(i)) ans.push_back(i);
        }
        
        return ans;
    }
};
