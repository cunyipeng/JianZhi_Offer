#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 40

typedef int Status;
typedef char String[MAXSIZE+1];

Status SetString(String T,char *chars)
{
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

void get_next(String T,  int *next)
{
	int i,j;
  	i=1;
  	j=0;
  	next[1]=0;
  	while (i<T[0])
 	{
    	if(j==0 || T[i]== T[j])
		{
      		++i;
			++j;
			next[i] = j;
    	}
		else
			j= next[j];
  	}
}

int KMP(String S,  String T,  int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T,  next);
	while (i <= S[0] && j <= T[0])
	{
		if (j==0 || S[i] == T[j])
      	{
         	++i;
         	++j;
      	}
      	else
      	 	j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

int main()
{
	String S, L, s, l;
	printf("请输入主串S:\n");
    scanf("%s",s);
    SetString(S, s);
    printf("请输入子串L:\n");
    scanf("%s", l);
    SetString (L, l);
    printf("\n%s在%s的第%d的位置\n", l, s, KMP(S, L, 1));
	return 0;
}
