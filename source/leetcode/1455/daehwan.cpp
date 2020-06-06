class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        vector<string> p;
        string del = " ";
        size_t i = 0;
        size_t j = s.find(del, i);
        while(j != string::npos){
            p.push_back(s.substr(i, j-i));
            i = j+del.length();
            j = s.find(del,i);
        }
        p.push_back(s.substr(i,j));
        
        bool f = false;
        int ans = 1;
        for(auto& str : p){
            if(0 == str.find(t)){f=true; break;}
            else ans++;
        }
        if(f) return ans;
        else return -1;
    }
};
