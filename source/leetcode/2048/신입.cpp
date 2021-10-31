class Solution {
public:
    int cnt[7] = {0,1,2,3,4,5,6};
    vector<int> balancedNums;
    
    void build(int num)
    {
        if(num > 1224444) return;
        
        bool isBalanced = true;
        
        for(int i=0;i<7;i++)
        {
            if(cnt[i] != 0 && cnt[i] != i)
            {
                isBalanced = false;
                break;
            }
        }
        
        if(isBalanced) balancedNums.push_back(num);
        
        for(int i=0;i<7;i++)
        {
            if(cnt[i] > 0)
            {
                cnt[i]--;
                build(num*10+i);
                cnt[i]++;
            }
        }
    }
    
    int nextBeautifulNumber(int n) {
        build(0);
        sort(balancedNums.begin(), balancedNums.end());
        return *lower_bound(balancedNums.begin(), balancedNums.end(), n+1);
    }
};
