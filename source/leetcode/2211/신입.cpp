class Solution {
public:
    int countCollisions(string directions) {
        vector<int> collisionIdx(directions.size(), -1);
        stack<int> RIdxes;
        
        for(int i=0;i<directions.size();i++)
        {
            if(directions[i] == 'R') RIdxes.push(i);
            else
            {
                while(!RIdxes.empty())
                {
                    collisionIdx[RIdxes.top()] = i;
                    RIdxes.pop();
                }
            }
        }
        
        stack<int> LIdxes;
        
        for(int i=directions.size()-1;i>=0;--i)
        {
            if(directions[i] == 'L') LIdxes.push(i);
            else
            {
                while(!LIdxes.empty())
                {
                    collisionIdx[LIdxes.top()] = i;
                    LIdxes.pop();
                }
            }
        }
        
        int cnt = 0;
        for(int idx : collisionIdx)
        {
            if(idx != -1) cnt++;
        }
        
        return cnt;
    }
};
