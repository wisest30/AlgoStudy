class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        int ret = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]<=q && q<=e[i]) ret++;
        }
        return ret;
    }
};
