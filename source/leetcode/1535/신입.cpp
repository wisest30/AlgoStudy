class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        list<int> arrToList;
        
        for(int num : arr) arrToList.push_back(num);
        
        k = min(k, (int)arr.size());
        
        int before = -1;
        int count = 0;
        
        int small = -1;
        int big = -1;
        
        for(int i=0;i<arr.size();i++)
        {
            auto it = arrToList.begin();
            
            int first = *it;
            int second = *(++it);
            
            arrToList.erase(it);
            arrToList.erase(arrToList.begin());
            
            small = min(first, second);
            big = max(first, second);
            
            arrToList.push_front(big);
            arrToList.push_back(small);
            
            if(big == before) count++;
            else
            {
                before = big;
                count = 1; 
            }
            
            if(count == k) break;
        }
        
        return big;
    }
};
