class Solution {
public:
    vector<string> stringMatching(vector<string>& w) {
        set<int> s;
        int n = (int)w.size();
        for(int i=0; i<n; i++){
          size_t found;
          for(int j=0; j<n; j++){
            if(i==j) continue;
            found = w[i].find(w[j]);
            if(found != string::npos) s.insert(j);
          }
        }
        vector<string> ret;
        for(auto i : s){
          ret.push_back(w[i]);
        }
        return ret;
    }
};
