class Solution {
public:
    int countPoints(string rings) {
        map<char, int> mapping;
        mapping['R'] = 4;
        mapping['G'] = 2;
        mapping['B'] = 1;
        
        int n = rings.size();
        int bits[10]{};
        
        for(int i=0;i<n;i+=2) bits[rings[i+1]-'0'] |= mapping[rings[i]];    
        
        int ans = 0;
        
        for(int i=0;i<10;i++)
        {
            if(bits[i] == 7) ans++;
        }
        
        return ans;
    }
};
