class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> eta(dist.size());
        for(int i=0; i< eta.size(); i++)
            eta[i]=1.0*dist[i]/speed[i];
        
        sort(eta.begin(),eta.end());
        int ret=0;
        for(double i=0.0; i<eta.size();i+=1.0){
            if(eta[(int)i]>i)ret++;
            else break;
        }
        return ret;
    }
};
