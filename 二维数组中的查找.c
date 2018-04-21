class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int i,j;
        for(i=0,j=col-1;i<row&&j>=0;)
        {
            if(target==array[i][j])
                return true;
            if(target<array[i][j])
            {
                j--;
                continue;
            }
            if(target>array[i][j])
            {
                i++;
                continue;
            }
        }
        return false;
    }
};
