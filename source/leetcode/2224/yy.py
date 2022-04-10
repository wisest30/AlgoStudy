class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        cur_hour,cur_min=int(current.split(":")[0]),int(current.split(":")[1])
        cur_sum=cur_hour*60+cur_min
        cor_hour,cor_min=int(correct.split(":")[0]),int(correct.split(":")[1])
        cor_sum=cor_hour*60+cor_min
        total_diff=cor_sum-cur_sum
        time_list=[60,15,5,1]
        change_count=0
        for time_ in time_list:
            change_count+=total_diff//time_
            total_diff%=time_
        return change_count
