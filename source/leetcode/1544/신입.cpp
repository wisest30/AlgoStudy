class Solution {
public:
    string makeGood(string s) {
        int n = (int)s.size();
        
        for(int i=0;i<n;i++)
        {
            vector<int> deleted(s.size(), 0);
            bool changed = false;
            
            for(int j=0;j<(int)s.size()-1;j++)
            {
                if((s[j+1]-s[j]) == ('A'-'a') || (s[j+1]-s[j]) == ('a'-'A'))
                {
                    changed = true;
                    deleted[j] = 1;
                    deleted[j+1] = 1;
                    j++;
                }
            }
            
            if(!changed) break;
            
            string newS;
            
            for(int j=0;j<s.size();j++)
            {
                if(deleted[j] == 0) newS.push_back(s[j]);
            }
            
            s = newS;
        }
        
        return s;
    }
};
