
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {

        int cost = 0;
        const int n = instructions.size();
        if (n > 0)
        {
            vector<int> nums;
            const int m = 1000000007;

            nums.push_back(instructions[0]);

            for (int i = 1; i < n; i++)
            {
                const int ins = instructions[i];
                const int s = nums.size();
                int k = 0;

                while (1)
                {                    
                    if (ins > nums[k])
                    {
                        ;
                    }
                    else
                    {
                        nums.insert(nums.begin() + k, ins);
                        cost = (cost + k) % m;
                        break;
                    }

                    if (ins < nums[s - k - 1])
                    {
                        ;
                    }
                    else
                    {
                        nums.insert(nums.end() - k, ins);
                        cost = (cost + k) % m;
                        break;
                    }
                    
                    k++;
                }

            }
        }

        return cost;
    }
};
