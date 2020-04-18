class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        int num = 0;
        vector<int> rev_s;
        for(int i = s.size()-1; i >= 0; i--){
            rev_s.push_back(s[i] -'0');
        }
        
        for(int i = 0; i < rev_s.size();){
            if( rev_s[i] == 0){
                step++;
                i++;
            }
            else if(rev_s[i] == 2){
                if( i == rev_s.size() - 1)
                    rev_s.push_back(1);
                else
                    rev_s[i+1]++;
                rev_s[i] = 0;
            }
            else{
                if( i == rev_s.size() - 1)    
                    break;
                step++;
                rev_s[i+1]++;
                rev_s[i] = 0;
            }
            
                
        }
        
        return step;
    }
};
