struct queryWithIdx
{
    int query;
    int idx;
};

bool operator<(const queryWithIdx &a, const queryWithIdx &b)
{
    return a.query < b.query;
}

struct Event
{
    int time;
    int sz;
};

bool operator<(const Event &a, const Event &b)
{
    return a.time < b.time;
}

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<queryWithIdx> queryWithIdxes;
        vector<Event> events;
        vector<int> ans(queries.size());
        
        for(int i=0;i<queries.size();i++) queryWithIdxes.push_back({queries[i], i});
        for(auto &interval : intervals)
        {
            events.push_back({interval[0], interval[1]-interval[0] + 1});
            events.push_back({interval[1]+1, interval[0]-interval[1] - 1});
        }
        
        sort(queryWithIdxes.begin(), queryWithIdxes.end());
        sort(events.begin(), events.end());
        
        int eventsCur = 0;
        map<int, int> curSizeCnt;
        
        for(auto &thisQuery : queryWithIdxes)
        {
            while(eventsCur < events.size() && events[eventsCur].time <= thisQuery.query)
            {
                if(events[eventsCur].sz > 0) curSizeCnt[events[eventsCur].sz]++;
                else 
                {
                    curSizeCnt[-events[eventsCur].sz]--;
                    if(curSizeCnt[-events[eventsCur].sz] == 0) curSizeCnt.erase(-events[eventsCur].sz);
                }
                eventsCur++;
            }
            if(curSizeCnt.empty()) ans[thisQuery.idx] = -1;
            else ans[thisQuery.idx] = curSizeCnt.begin()->first;
        }
        
        return ans;
    }
};
