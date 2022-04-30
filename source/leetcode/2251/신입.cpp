enum Type
{
    ADD,
    DEL,
    VIEW
};

struct Event
{
    int time;
    Type type;
    int idx;
};

bool operator<(const Event &a, const Event &b)
{
    if(a.time != b.time) return a.time < b.time;
    return a.type < b.type;
}

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<Event> events;
        
        for(auto &flower : flowers)
        {
            events.push_back({flower[0], ADD, 0});
            events.push_back({flower[1]+1, DEL, 0});
        }
        
        int i=0;
        for(auto &person : persons) events.push_back({person, VIEW, i++});
        
        sort(events.begin(), events.end());
        
        int cur = 0;
        vector<int> ans(persons.size());
        
        for(auto &event : events)
        {
            if(event.type == ADD) cur++;
            else if(event.type == DEL) cur--;
            else ans[event.idx] = cur;
        }
        
        return ans;    
    }
};
