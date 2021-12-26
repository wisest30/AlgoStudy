class Solution {
public:
    bool isPalindrome(string &str)
    {
        int n = str.size();
        for(int i=0;i<n/2;i++)
        {
            if(str[i] != str[n-1-i]) return false;
        }
        
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(string &word : words)
        {
            if(isPalindrome(word)) return word;
        }
        return ans;
    }
};
