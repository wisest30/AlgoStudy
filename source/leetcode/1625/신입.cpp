class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> visited;
        
        queue<string> q;
        q.push(s);
        
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            
            string afterAdd = cur;
            string afterRotate = cur;
            
            reverse(afterRotate.begin(), afterRotate.end());
            reverse(afterRotate.begin(), afterRotate.begin()+b);
            reverse(afterRotate.begin()+b, afterRotate.end());
            
            for(int i=1;i<afterAdd.size();i+=2)
            {
                int num = afterAdd[i]-'0';
                afterAdd[i] = (num + a)%10 + '0';
            }
            
            //cout << cur << " " << afterAdd << " " << afterRotate << "\n";
            
            if(visited.find(afterAdd) == visited.end())
            {
                visited.insert(afterAdd);
                q.push(afterAdd);
            }
            if(visited.find(afterRotate) == visited.end())
            {
                visited.insert(afterRotate);
                q.push(afterRotate);
            }
        }
        
        return *visited.begin();
    }
};
