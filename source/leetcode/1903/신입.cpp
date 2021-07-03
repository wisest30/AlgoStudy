class Solution {
public:
    string largestOddNumber(string num) {
        int len = 0;
        
        for(int i=0;i<num.size();i++)
        {
            if((num[i]-'0')%2) len = i+1; 
        }
        
        return num.substr(0, len);
    }
};
