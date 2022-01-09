class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        
        long long sum = mass;
        
        for(int thisMass : asteroids)
        {
            if(thisMass > sum) return false;
            sum += thisMass;
        }
        
        return true;
    }
};
