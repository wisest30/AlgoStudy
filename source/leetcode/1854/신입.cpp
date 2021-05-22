class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int population[2050+5]{};
        
        for(auto &log : logs)
        {
            for(int i=log[0];i<log[1];i++) population[i]++;
        }
        
        int mx = 0;
        int mxYear = -1;
        
        for(int i=1950;i<=2050;i++)
        {
            if(population[i] > mx)
            {
                mx = population[i];
                mxYear = i;
            }
        }
        
        return mxYear;
    }
};
