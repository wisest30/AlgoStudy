class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> transform(dist.size(),0);
        vector<int> check(100001,0);
        int MAX = 0;
        int ret = 0;
        for(int i = 0; i < dist.size(); i++){
            if(dist[i]%speed[i] != 0)
                transform[i] = dist[i] / speed[i] + 1;
            else
                transform[i] = dist[i] / speed[i];
            if(MAX < transform[i])
                MAX = transform[i];
            check[transform[i]]++;
        }
        for(int i = 1; i < MAX + 1; i++){
            check[i] = check[i - 1] + check[i];
            if(check[i] > i){
                ret = i;
                break;
            }
            else{
                ret = check[i];
            }
        }
        return ret;
    }
};
