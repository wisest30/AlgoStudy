class Solution {
public:
    vector<string> getFolderNames(vector<string>& ns) {
        map<string,int> m;
        vector<string> ret;
        for(auto& n : ns){
            if(m[n]==0) {m[n]++; ret.push_back(n);}
            else{
                int k = m[n]++;
                while(1){
                    string tmp = n+"("+to_string(k)+")";
                    if(m[tmp]==0){
                        ret.push_back(tmp);
                        m[tmp]++;
                        break;
                    }
                    k++;
                }
            }
        }
        return ret;
    }
};
