class Solution {
public:
    bool isAlphabet(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }
    
    bool isValid(string &str)
    {
        int hyphenCnt = 0;
        int punctuationCnt = 0;
        
        for(int i=0;i<str.size();i++)
        {
            char ch = str[i];
            
            if(ch == '-') 
            {
                hyphenCnt++;
                if(i == 0 || i == str.size()-1 || !isAlphabet(str[i-1]) || !isAlphabet(str[i+1])) return false;
            }
            else if(ch == '.' || ch == ',' || ch == '!') 
            {
                punctuationCnt++;
                if(i != (int)str.size()-1) return false;
            }
            else if(isAlphabet(ch)) continue;
            else return false;
        }
        
        if(hyphenCnt > 1 || punctuationCnt > 1) return false;
        return true;
    }
    
    int countValidWords(string sentence) {
        string str = "";
        sentence += " ";
        int ans = 0;
        
        for(char ch : sentence)
        {
            if(ch == ' ')
            {
                if(!str.empty()) ans += isValid(str);
                str = "";
            }
            else str += ch;
        }
        
        return ans;
    }
};
