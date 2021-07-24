class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>> hashIndexSave;
        
        int ret=0;
        for(int i=0;i<s.length();i++){
            hashIndexSave[s[i]].push_back(i);
        }
        
        for(char c='a'; c<='z';c++){

            if(hashIndexSave[c].size()>1){
                int left=hashIndexSave[c][0];
                int right=hashIndexSave[c].back();
                if(hashIndexSave[c].size()>2)
                    ret++;
            
                for(char y='a'; y<='z';y++){
                    if(y==c)continue;
                    vector<int> & indexList = hashIndexSave[y];
                    if(indexList.empty())continue;
                    if(upper_bound(indexList.begin(),indexList.end(),left)!= upper_bound(indexList.begin(),indexList.end(),right))
                        ret++;
                
                }
            }
        }
        return ret;
        
        
    }
};
