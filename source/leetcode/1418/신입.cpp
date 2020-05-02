class Solution {
public:
    string convertFromNum(int num)
    {
        string res = "";
        while(num)
        {
            res += (num%10) + '0';
            num/=10;
        }
        reverse(res.begin(), res.end());
        if(res == "") return "0";
        return res;
    }
    
    int convertFromStr(string &str)
    {
        int res = 0;
        for(int i=0;i<str.size();++i) res = res*10 + (str[i] - '0');
        return res;
    }
    
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> table;
        set<string> foods;
        vector<vector<string>> ans;
        
        for(int i=0;i<orders.size();++i)
        {
            table[convertFromStr(orders[i][1])][orders[i][2]]++;
            foods.insert(orders[i][2]);
        }
        
        vector<string> temp;
        temp.push_back("Table");
        for(auto it = foods.begin(); it != foods.end(); it++) temp.push_back(*it);
        ans.push_back(temp);
        
        for(auto it = table.begin(); it != table.end(); it++)
        {
            temp.clear();
            temp.push_back(convertFromNum(it->first));
            for(int i=1;i<ans[0].size();++i) temp.push_back(convertFromNum((it->second)[ans[0][i]]));
            ans.push_back(temp);
        }
        
        return ans;
    }
};
