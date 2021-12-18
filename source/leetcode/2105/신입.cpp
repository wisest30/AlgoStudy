class Solution {
public:
    int ans;
    
    void waterFill(int &q, int capacity, int &plant)
    {
        if(q < plant)
        {
            ans++;
            q = capacity;
        }
        q -= plant;
        plant = 0;
    }
    
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        
        int aCur = 0;
        int bCur = n-1;
        
        int aQ = capacityA;
        int bQ = capacityB;
        
        while(aCur < n && bCur >= 0)
        {
            if(aCur == bCur)
            {
                if(bQ > aQ) waterFill(bQ, capacityB, plants[bCur]);
                else waterFill(aQ, capacityA, plants[aCur]);
            }
            
            waterFill(aQ, capacityA, plants[aCur]);
            waterFill(bQ, capacityB, plants[bCur]);
            
            aCur++;
            bCur--;
        }
        
        return ans;
    }
};
