class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        auto s = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3));
        auto f = stoi(finishTime.substr(0, 2)) * 60 + stoi(finishTime.substr(3));
        
        while(s % 15)
            s++;
        
        if(f < s) f += 24 * 60;
        return (f - s) / 15;
    }
};
