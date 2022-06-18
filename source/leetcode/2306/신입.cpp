typedef long long ll;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        for(string& idea : ideas) 
        {
            idea.push_back('#');
            reverse(idea.begin(), idea.end());
        }
        
        unordered_map<string, int> has;
                
        for(string& idea : ideas) has[idea.substr(0, idea.size()-1)] |= (1<<(idea.back()-'a'));
                
        ll ans = 0;
        
        for(char ch1='a';ch1<='z';ch1++)
        {
            for(char ch2='a';ch2<='z';ch2++)
            {
                if(ch1 == ch2) continue;
                
                int has1Sz = 0;
                int has2Sz = 0;
                
                for(auto& [k, v] : has)
                {
                    if((v&(1<<(ch1-'a'))) && !(v&(1<<(ch2-'a')))) has1Sz++;
                    if((v&(1<<(ch2-'a'))) && !(v&(1<<(ch1-'a')))) has2Sz++;
                }
                
                //cout << ch1 << ch2 << " " << has1Sz << " " << has2Sz << "\n";
                ans += 1LL * has1Sz * has2Sz;
            }
        }
        
        return ans;
    }
};
