class Solution {
public:
    int convertStr2Int(string &str)
    {
        int hour = (str[0]-'0')*10 + str[1]-'0';
        int min = (str[3]-'0')*10 + str[4]-'0';
        
        return 60*hour + min;
    }
    
    int convertTime(string current, string correct) {
        int divide[4] = {60, 15, 5, 1};
        int diff = convertStr2Int(correct) - convertStr2Int(current);
        int ans = 0;
        
        for(int i=0;i<4;i++)
        {
            ans += diff / divide[i];
            diff %= divide[i];
        }
        
        return ans;
    }
};
