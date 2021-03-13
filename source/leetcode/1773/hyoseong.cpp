class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {        
        int ret = 0;
        for(auto& item : items) {
            if(ruleKey == "type" && ruleValue == item[0]) ret++;
            else if(ruleKey == "color" && ruleValue == item[1]) ret++;
            else if(ruleKey == "name" && ruleValue == item[2]) ret++;
        }
        
        return ret;
    }
};
