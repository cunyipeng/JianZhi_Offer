class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {  
      if(str==NULL||rows<=0||cols<=0||matrix==NULL)
           return false;
      bool *isOk = new bool[rows*cols]();
      for(int i=0; i<rows; i++)
      {
           for(int j=0; j<cols; j++)
                if(isHasPath(matrix, rows, cols, str, isOk, i, j))
                   return true;
      }
      return false;
    }
    bool isHasPath(char *matrix, int rows, int cols, char *str, bool *isOk, int curx ,int cury)
    {
      if(*str=='\0')
           return true;
      if(curx<0||curx>=rows)
           return false;
      if(isOk[curx * cols + cury] || *str != matrix[curx * cols + cury])
           return false;
      isOk[curx*cols+cury]=true;
      bool sign=isHasPath(matrix,rows,cols,str+1,isOk,curx-1,cury)
       ||isHasPath(matrix,rows,cols,str+1,isOk,curx+1,cury)
       ||isHasPath(matrix,rows,cols,str+1,isOk,curx,cury-1)
       ||isHasPath(matrix,rows,cols,str+1,isOk,curx,cury+1);
      isOk[curx*cols+cury]=false;
      return sign;
   }
};
