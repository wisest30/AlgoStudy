class Solution {
public:
    int str2int(string &str)
    {
        int res = 0;
        
        for(char ch : str) res = res * 10 + ch - '0';
        
        return res;
    }
    
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        vector<int> oddIdx;
        vector<int> evenIdx;
        
        string str = to_string(num);
        
        for(int i=0;i<str.size();i++)
        {
            char ch = str[i];
            
            if((ch-'0')%2)
            {
                odd.push_back(ch-'0');
                oddIdx.push_back(i);
            }
            else
            {
                even.push_back(ch-'0');
                evenIdx.push_back(i);
            }
        }
        
        string res(str.size(), ' ');
        
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        for(int i=0;i<oddIdx.size();i++)
        {
            res[oddIdx[i]] = odd.back() + '0';
            odd.pop_back();
        }
        
        for(int i=0;i<evenIdx.size();i++)
        {
            res[evenIdx[i]] = even.back() + '0';
            even.pop_back();
        }
        
        return str2int(res);
    }
};
