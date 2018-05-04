class Solution {    
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> max_vec;
        max_vec.clear();
        int rows = matrix.size();
        int columns = matrix[0].size();
        int start = 0;
        int endX;
        int endY;
        
        // 输入的二维数组非法，返回空的数组
        if (rows == 0 || columns == 0)  return max_vec;
        while(rows > start * 2 && columns > start * 2){
            
           endX = rows - 1 - start;
           endY = columns - 1 - start;
        
           for(int i = start; i <= endY; ++i)
               max_vec.push_back(matrix[start][i]);
        
           if(start < endX)
               for(int i = start + 1; i <= endX; ++i)
                   max_vec.push_back(matrix[i][endY]);
        
           if(start < endX && start < endY)
               for(int i = endY - 1; i >= start; --i)
                   max_vec.push_back(matrix[endX][i]);
         
        
          if(start < endY && start < endX - 1)
               for(int i = endX - 1; i >= start + 1; --i)
                   max_vec.push_back(matrix[i][start]);
          ++start;
        }
        return max_vec;
    }
};
