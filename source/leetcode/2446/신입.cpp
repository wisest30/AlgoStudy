class Solution {
public:
    int convertToMin(string& str)
    {
        return 600*(str[0]-'0') + 60*(str[1]-'0') + 10*(str[3]-'0') + (str[4]-'0');
    }
    
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int ev1StMin = convertToMin(event1[0]);
        int ev1EdMin = convertToMin(event1[1]);
        
        int ev2StMin = convertToMin(event2[0]);
        int ev2EdMin = convertToMin(event2[1]);
        
        if(ev1EdMin >= ev2StMin && ev1StMin <= ev2EdMin) return true;
        if(ev2EdMin >= ev1StMin && ev2StMin <= ev1EdMin) return true;
        
        return false;
    }
};
