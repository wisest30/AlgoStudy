class Solution {
public:
    vector<int> processQueries(vector<int>& qq, int m) {
        deque<int> dq;
        vector<int> ret;
        for(int i=1; i<=m; i++) dq.push_back(i);
        for(auto q : qq){
          for(int i=0; i<m; i++){
            if(dq[i]==q){
                dq.erase(dq.begin()+i);
                dq.push_front(q);
                ret.push_back(i);
                break;
            }
          }
        }
        return ret;
    }
};
