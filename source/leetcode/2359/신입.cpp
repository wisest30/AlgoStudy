class Solution {
public:
    vector<int> edges;
    vector<int> fromNode1;
    vector<int> fromNode2;
    int n;
    
    void updateFrom(vector<int>& distVec, int curNode, int curDist)
    {
        if(distVec[curNode] != INT_MAX) return;
        distVec[curNode] = curDist;
        if(edges[curNode] != -1) updateFrom(distVec, edges[curNode], curDist+1);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        this->edges = edges;
        n = edges.size();
        
        fromNode1 = fromNode2 = vector<int>(n, INT_MAX);
        
        updateFrom(fromNode1, node1, 0);
        updateFrom(fromNode2, node2, 0);
        
        int ansDist = INT_MAX;
        int ansNode = -1;
        
        for(int i=0;i<n;i++)
        {
            int curDist = max(fromNode1[i], fromNode2[i]);
            if(curDist < ansDist)
            {
                ansDist = curDist;
                ansNode = i;
            }
        }
        
        return ansNode;
    }
};
