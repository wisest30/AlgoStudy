class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        
        for(string& operation : operations)
        {
            for(char ch : operation)
            {
                if(ch == '+')
                {
                    ans++;
                    break;
                }
                else if(ch == '-')
                {
                    ans--;
                    break;
                }
            }
        }
        
        return ans;
    }
};
