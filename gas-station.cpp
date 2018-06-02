class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int end = 0;
        int start = gas.size() - 1;
        int sum = gas[start] - cost[start];
        while(start > end)
        {
            if(sum >= 0)
            {
                sum += gas[end] - cost[end];
                ++end;
            }
            else
            {
                --start;
                sum += gas[start] - cost[start];
            }
        }
        if(sum >= 0)
            return start;
        else
            return -1;
    }
};
