class Solution {
public:
    int lostCnt[1'00000+5];
    
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        
        for(auto &match : matches)
        {
            lostCnt[match[1]]++;
            players.insert(match[0]);
            players.insert(match[1]);
        }
        
        vector<int> zeroLost;
        vector<int> oneLost;
        
        for(auto it = players.begin(); it != players.end() ; it++)
        {
            if(lostCnt[*it] == 0) zeroLost.push_back(*it);
            else if(lostCnt[*it] == 1) oneLost.push_back(*it);
        }
        
        return {zeroLost, oneLost};
    }
};
