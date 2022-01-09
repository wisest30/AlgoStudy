class Solution {
public:
    bool checkString(string s) {
        bool bAppears = false;
        
        for(char ch : s)
        {
            if(ch == 'b') bAppears = true;
            else
            {
                if(bAppears) return false;
            }
        }
        
        return true;
    }
};
