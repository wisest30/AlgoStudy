typedef long long ll;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> evenNums;
        vector<int> oddNums;
        vector<int> evenTarget;
        vector<int> oddTarget;
        
        for(int num : nums)
        {
            if(num%2) oddNums.push_back(num);
            else evenNums.push_back(num);
        }
        
        for(int num : target)
        {
            if(num%2) oddTarget.push_back(num);
            else evenTarget.push_back(num);
        }
        
        sort(evenNums.begin(), evenNums.end());
        sort(oddNums.begin(), oddNums.end());
        sort(evenTarget.begin(), evenTarget.end());
        sort(oddTarget.begin(), oddTarget.end());
        
        ll ans = 0;
        
        for(int i=0;i<evenNums.size();i++)
        {
            if(evenNums[i] > evenTarget[i]) ans += (evenNums[i] - evenTarget[i])/2;
        }
        
        for(int i=0;i<oddNums.size();i++)
        {
            if(oddNums[i] > oddTarget[i]) ans += (oddNums[i] - oddTarget[i])/2;
        }
        
        return ans;
    }
};
