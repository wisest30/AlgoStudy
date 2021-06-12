namespace {
    struct server {
        int weight;
        int freeTime;
        int idx;
    };
    
    bool operator<(server a, server b) {
        if(a.freeTime != b.freeTime)
            return a.freeTime > b.freeTime;
        else if(a.weight != b.weight)
            return a.weight > b.weight;
        else
            return a.idx > b.idx;
    }
}

class Solution {
public:    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        auto ret = vector<int>(tasks.size());
        
        priority_queue<server> freeQueue, waitQueue;
        for(auto i = 0; i < servers.size(); ++i)
            freeQueue.push({servers[i], 0, i});
        
        int curTime = 0, taskIdx = 0;
        while(taskIdx < tasks.size()) {
            while(!waitQueue.empty() && waitQueue.top().freeTime <= curTime) {
                auto server = waitQueue.top();
                waitQueue.pop();
                server.freeTime = 0;
                freeQueue.push(server);
            }
            
            if(curTime < taskIdx)
                curTime = taskIdx;
            else if(freeQueue.empty())
                curTime = waitQueue.top().freeTime;
            else {
                auto server = freeQueue.top();
                freeQueue.pop();
                ret[taskIdx] = server.idx;
                server.freeTime = curTime + tasks[taskIdx];
                waitQueue.push(server);
                taskIdx++;
            }
        }
        
        return ret;
    }
};
