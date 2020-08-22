class Solution {
public:
    void invertStr(string &str)
    {
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
    }
    
    char findKthBit(int n, int k) {
        string S = "0";
        
        for(int i=0;i<n;i++)
        {
            string invertedS = S;
            invertStr(invertedS);
            reverse(invertedS.begin(), invertedS.end());
            S = S + "1" + invertedS;
        }
        
        return S[k-1];
    }
};
