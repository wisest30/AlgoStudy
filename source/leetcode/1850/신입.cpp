class Solution {
public:
    int getMinSwaps(string num, int k) {
        vector<int> originalNumVec;
        vector<int> numVec;
        int lastPos[10]{};
        
        for(char ch : num) 
        {
            originalNumVec.push_back(ch-'0');
            numVec.push_back(ch-'0');
        }
        
        while(k--)
        {
            memset(lastPos, 0, sizeof(lastPos));
            
            for(int i=(int)numVec.size()-1;i>=0;--i)
            {
                bool swapped = false;
                
                for(int j=numVec[i]+1;j<10;j++)
                {
                    if(lastPos[j])
                    {
                        swapped = true;
                        int temp = numVec[i];
                        numVec[i] = j;
                        numVec[lastPos[j]] = temp;
                        sort(numVec.begin()+i+1, numVec.end());
                        break;
                    }
                }
                if(swapped) break;
                
                if(lastPos[numVec[i]] == 0) lastPos[numVec[i]] = i;
            }
            
            /*
            for(int i=0;i<numVec.size();i++) printf("%d", numVec[i]);
            printf("\n");
            */
        }
        
        int ans = 0;
        
        /*
        for(int i=0;i<numVec.size();i++) printf("%d", numVec[i]);
        printf("\n");
        for(int i=0;i<numVec.size();i++) printf("%d", originalNumVec[i]);
        printf("\n");
        */
        
        for(int i=0;i<numVec.size();i++)
        {
            if(numVec[i] == originalNumVec[i]) continue;
            
            int targetPos = -1;
            
            for(int j=i+1;j<numVec.size();j++)
            {
                if(originalNumVec[j] == numVec[i])
                {
                    targetPos = j;
                    break;
                }
            }
            
            while(numVec[i] != originalNumVec[i])
            {
                swap(originalNumVec[targetPos], originalNumVec[targetPos-1]);
                ans++;
                targetPos--;
            }
        }
        
        return ans;
    }
};
