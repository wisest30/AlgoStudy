class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start_time = atoi(startTime.substr(0,2).c_str());
        int finish_time = atoi(finishTime.substr(0,2).c_str());
        int start_min = atoi(startTime.substr(3,2).c_str());
        int finish_min = atoi(finishTime.substr(3,2).c_str());

        if(start_time == finish_time && finish_min - start_min < 15 && finish_min - start_min >= 0)
            return 0;
        else{
            if(start_min <= 15 && start_min > 0)
                start_min = 15;
            else if(start_min <= 30 && start_min > 15)
                start_min = 30;
            else if(start_min <= 45 && start_min > 30)
                start_min = 45;
            else{
                if(start_min != 0){
                    start_min = 0;
                    start_time = start_time + 1;
                    if(start_time >= 24)
                        start_time -= 24;
                }
            }

            if(finish_min < 15 && finish_min >= 0)
                finish_min = 0;
            else if(finish_min < 30 && finish_min >= 15)
                finish_min = 15;
            else if(finish_min < 45 && finish_min >= 30)
                finish_min = 30;
            else
                finish_min = 45;

            if(finish_time > start_time){
                if(finish_min >= start_min)
                    return (finish_time - start_time) * 4 + (finish_min - start_min) / 15;
                else
                    return (finish_time - start_time - 1) * 4 + (60 + finish_min - start_min) / 15;
            }
            else if(finish_time < start_time){
                if(finish_min >= start_min)
                    return (24 + finish_time - start_time) * 4 + (finish_min - start_min) / 15;
                else
                    return (24 + finish_time - start_time - 1) * 4 + (60 + finish_min - start_min) / 15;
            }
            else{
                if(finish_min >= start_min)
                    return (finish_time - start_time) * 4 + (finish_min - start_min) / 15;
                else
                    return (24 + finish_time - start_time - 1) * 4 + (60 + finish_min - start_min) / 15;
            }
        }
    }
};