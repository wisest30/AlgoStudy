struct Element
{
    int arrow;
    int score;
    int selected;
};

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> mxScore(numArrows+1, -1);
        vector<int> select(numArrows+1, 0);
        
        vector<Element> elements(12, {0, 0});
        mxScore[0] = 0;
        int ansIdx = 0;
        
        for(int i=0;i<12;i++)
        {
            elements[i].arrow = aliceArrows[i]+1;
            elements[i].score = i;
            elements[i].selected = 1<<i;
            
            for(int j=numArrows;j>=0;--j)
            {
                if(j-elements[i].arrow < 0) break;
                if(mxScore[j-elements[i].arrow] == -1) continue;
                if(mxScore[j-elements[i].arrow] + elements[i].score > mxScore[j])
                {
                    mxScore[j] = mxScore[j-elements[i].arrow] + elements[i].score;
                    select[j] = select[j-elements[i].arrow] | elements[i].selected;
                }
                if(mxScore[j] > mxScore[ansIdx]) ansIdx = j;
            }
        }
        
        vector<int> bobArrows(12, 0);
        int sum = 0;
        
        for(int i=0;i<12;i++)
        {
            if(select[ansIdx]&(1<<i)) bobArrows[i] = aliceArrows[i]+1;
            sum += bobArrows[i];
        }
        
        if(sum != numArrows)
        {
            for(int i=0;i<12;i++)
            {
                if(bobArrows[i]) 
                {
                    bobArrows[i] += numArrows - sum;
                    break;
                }
            }
        }
        
        return bobArrows;
    }
};
