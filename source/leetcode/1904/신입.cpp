class Solution {
public:
    int convertToMinute(string &time)
    {
        int hour, minute;
        
        sscanf(time.c_str(), "%d:%d", &hour, &minute);
        
        return hour*60 + minute;    
    }
    
    int numberOfRounds(string startTime, string finishTime) {
        int stMin = convertToMinute(startTime);
        int edMin = convertToMinute(finishTime);
        
        if(stMin > edMin) edMin += 24*60;
        
        if(stMin%15) stMin = (stMin/15+1)*15;
        return (edMin-stMin)/15;
    }
};
