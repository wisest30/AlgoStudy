class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1;
        int a = capacityA, b = capacityB;
        int ret = 0;
        
        while(i <= j) {
            if(i == j) {
                if(max(a, b) < plants[i])
                    ++ret;
                break;
            } else {
                if(a < plants[i])
                    ++ret, a = capacityA;
                if(b < plants[j])
                    ++ret, b = capacityB;
                
                a -= plants[i++], b -= plants[j--];
            }
        }
        
        return ret;
    }
};
