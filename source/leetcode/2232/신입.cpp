class Solution {
public:
    int getNum(string &expr, int &cur)
    {
        int res = 0;
        
        for(;cur<expr.size();cur++)
        {
            if(expr[cur] < '0' || expr[cur] > '9') break;
            res = res * 10 + expr[cur] - '0';
        }
        
        cur++;
        
        return res;
    }
    
    string minimizeResult(string expression) {
        vector<string> twoNums;
        int cur = 0;
        
        twoNums.push_back(to_string(getNum(expression, cur)));
        twoNums.push_back(to_string(getNum(expression, cur)));
        
        int ans = INT_MAX;
        int ansI = -1;
        int ansJ = -1;
        
        for(int i=0;i<=twoNums[0].size()-1;i++)
        {
            int leftMul = 1;
            if(i != 0)
            {
                leftMul = 0;
                for(int k=0;k<i;k++) leftMul = leftMul * 10 + twoNums[0][k] - '0';
            }
            
            int leftSum = 0;
            for(int k=i;k<twoNums[0].size();k++) leftSum = leftSum * 10 + twoNums[0][k] - '0';
            
            for(int j=1;j<=twoNums[1].size();j++)
            {
                int rightSum = 0;
                for(int k=0;k<j;k++) rightSum = rightSum * 10 + twoNums[1][k] - '0';
                
                int rightMul = 1;
                if(j != twoNums[1].size())
                {
                    rightMul = 0;
                    for(int k=j;k<twoNums[1].size();k++) rightMul = rightMul * 10 + twoNums[1][k] - '0'; 
                }
                
                int res = leftMul * (leftSum + rightSum) * rightMul;
                if(res < ans)
                {
                    ans = res;
                    ansI = i;
                    ansJ = j;
                }
            }
        }
        
        //cout << ans << "\n";
        
        string output;
        
        for(int i=0;i<ansI;i++) output += twoNums[0][i];
        output += '(';
        for(int i=ansI;i<twoNums[0].size();i++) output += twoNums[0][i];
        output += '+';
        for(int i=0;i<ansJ;i++) output += twoNums[1][i];
        output += ')';
        for(int i=ansJ;i<twoNums[1].size();i++) output += twoNums[1][i];
        
        return output;
    }
};
