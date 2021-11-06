class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
    	bool visited[1001] = {false};
    	vector<pair<int,int>> needCheckNums;
    	int size_needCheckNums = 0;
    	int size_nums = nums.size();

    	needCheckNums.push_back(make_pair(start, 0));
    	size_needCheckNums++;
    	visited[start] = true;

    	while(size_needCheckNums != 0){
    		int checkNum = needCheckNums[0].first;
    		int checkTimes = needCheckNums[0].second + 1;
    		needCheckNums.erase(needCheckNums.begin());
    		size_needCheckNums--;
            
            //cout << "checkNum : " << checkNum << " checkTimes : " << checkTimes << endl;
    		for(int i = 0; i < size_nums; i++){
    			int tmp = nums[i];
    			int plus = checkNum + tmp;
    			int minus = checkNum - tmp;
    			int xOR = checkNum ^ tmp;
    			if(plus == goal || minus == goal || xOR == goal)
    				return checkTimes;
    			if(plus >= 0 && plus <= 1000 && visited[plus] == false){
    				visited[plus] = true;
    				needCheckNums.push_back(make_pair(plus, checkTimes));
    				size_needCheckNums++;
                    //cout << "plus : " << plus << " checkTimes : " << checkTimes << endl;
    			}
    			if(minus <= 1000 && minus >= 0 && visited[minus] == false){
    				visited[minus] = true;
    				needCheckNums.push_back(make_pair(minus, checkTimes));
    				size_needCheckNums++;
                    //cout << "minus : " << minus << " checkTimes : " << checkTimes << endl;
    			}
				if(xOR <= 1000 && xOR >= 0 && visited[xOR] == false){
					visited[xOR] = true;
    				needCheckNums.push_back(make_pair(xOR, checkTimes));
    				size_needCheckNums++;
                    //cout << "xOR : " << xOR << " checkTimes : " << checkTimes << endl;
	    		}
    		}
    	}
    	return -1;
    }
};
