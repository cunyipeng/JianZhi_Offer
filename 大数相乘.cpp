
#include "oj.h"
#include <vector>
#include <string>

/*****************************************************************************
 Prototype    : multiply
 Description  : 两个任意长度的长整数相乘, 输出结果
 Input Param  : 
                const std::string strMultiplierA  乘数A
                const std::string strMultiplierB  乘数B
 Output       : 
                std::string strRst            乘法结果
 Return Value : 
                int                       0  正确  
                                         -1  异常
*****************************************************************************/
int multiply (const std::string a,const std::string b, std::string &c) 
{
    /* 在这里实现功能 */
    if(a.size() == 0 || b.size() == 0)
		return -1;
	if(a == "0" || b == "0")
	{
        c = "0";
		return 0;
	}
    vector<int> aa, bb, cc;
	for(int i = (int)a.size() - 1; i >= 0; i--)
		aa.push_back(a[i] - '0');
	for(int i = (int)b.size() - 1; i >= 0; i--)
		bb.push_back(b[i] - '0');
	for(int i = 0; i < (int)a.size() + (int)b.size(); i++)
		cc.push_back(0);

	for(int i = 0; i < (int)aa.size(); i++)
		for(int j = 0; j < (int)bb.size(); j++)
		{
			cc[i + j] += (aa[i] * bb[j]) % 10;
			cc[i + j + 1] += (aa[i] * bb[j]) / 10;
		}

	for(int i = 0; i < (int)aa.size() + (int)bb.size() - 1; i++)
	{
		cc[i + 1] += cc[i] / 10;
		cc[i] = cc[i] % 10;
	}

	if(cc[aa.size() +  bb.size() - 1] != 0)
	{
		for(int i = 0; i < (int)a.size() + (int)b.size(); i++)
		    c.push_back(0);
	 	c[0] = (char)(cc[aa.size() + bb.size() - 1] + '0');
	    for(int i = (int)aa.size() + (int)bb.size() - 2; i >= 0; i--)
            c[aa.size() + bb.size() - 1 - i] = (char)(cc[i] + '0');
	}
	else
	{
		for(int i = 0; i < (int)a.size() + (int)b.size() - 1; i++)
		    c.push_back(0);
	    for(int i = (int)aa.size() + (int)bb.size() - 2; i >= 0; i--)
            c[aa.size() + bb.size() - 2 - i] = (char)(cc[i] + '0');
	}

    return 0;
}
