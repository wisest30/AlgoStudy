class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string, int> hashStringMap;
        
        for(string& name : names)
        {
            if(hashStringMap.find(name) != hashStringMap.end())
            {
                int lastNum = hashStringMap[name];
                
                for(int i=1;;i++)
                {
                    string newName = name + "(" + to_string(lastNum+i) + ")";
                    if(hashStringMap.find(newName) == hashStringMap.end())
                    {
                        hashStringMap[name] = lastNum+i;
                        hashStringMap[newName] = 0;
                        ans.push_back(newName);
                        break;
                    }
                }
            }
            else 
            {
                hashStringMap[name] = 0;
                ans.push_back(name);
            }
        }
        
        return ans;
    }
};
