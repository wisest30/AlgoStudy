class Solution {
public:
    int sq(int num)
    {
        return num * num;
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        
        for(int x=0;x<=200;x++)
        {
            for(int y=0;y<=200;y++)
            {
                for(auto &circle : circles)
                {
                    if(sq(x-circle[0]) + sq(y-circle[1]) <= sq(circle[2])) 
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
