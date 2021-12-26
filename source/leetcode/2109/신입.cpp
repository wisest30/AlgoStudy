class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int spacesCur = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(spacesCur < spaces.size() && spaces[spacesCur] == i)
            {
                ans += " ";
                spacesCur++;
            }
            ans += s[i];
        }
        
        return ans;
    }
};
