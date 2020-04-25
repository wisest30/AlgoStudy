class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> subwords;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j <words.size(); j++){
                if( i == j)
                    continue;
                if( words[j].find(words[i]) != -1){
                    subwords.push_back(words[i]);
                    break;
                }
            }
        }
        
        return subwords;
    }
};
