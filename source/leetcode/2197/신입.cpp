class Solution {
public:
    int getLCM(int a, int b, int gcd)
    {
        return 1LL * a * b / gcd;
    }
    
    int getGCD(int a, int b)
    {
        if(a%b == 0) return b;
        return getGCD(b, a%b);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        while(true)
        {
            int beforeSz = nums.size();
           
            vector<int> leftNums;
            int before = nums[0];
            for(int i=1;i<nums.size();i++)
            {
                int gcd = getGCD(before, nums[i]);
                
                if(gcd == 1) 
                {
                    leftNums.push_back(before);
                    before = nums[i];
                }
                else before = getLCM(before, nums[i], gcd);
            }
            leftNums.push_back(before);
            
            vector<int> rightNums;
            before = leftNums.back();
            
            /*
            for(int num : leftNums) cout << num << " ";
            cout << "\n";
            */
            
            for(int i=(int)leftNums.size()-2;i>=0;--i)
            {
                int gcd = getGCD(before, leftNums[i]);
                
                if(gcd == 1)
                {
                    rightNums.push_back(before);
                    before = leftNums[i];
                }
                else before = getLCM(before, leftNums[i], gcd);
            }
            rightNums.push_back(before);
            reverse(rightNums.begin(), rightNums.end());
            
            /*
            for(int num : rightNums) cout << num << " ";
            cout << "\n";
            */
            
            if(rightNums.size() == beforeSz) break;
            nums = rightNums;
        }
        
        return nums;
    }
};
