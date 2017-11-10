// last_preMPSearch.cpp : 定义控制台应用程序的入口点。
//

#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int * BuildPreFunction(char * cpP, int iLenP)
{
	int * ipPreArray = (int *)malloc(sizeof(int) * (iLenP));
	int i;
	int last_pre = 0;

	memset(ipPreArray, 0, iLenP);

	for (i = 2;i <= iLenP; i++)
	{
		while (last_pre > 0 && cpP[last_pre + 1 - 1] != cpP[i - 1])
		{
			last_pre = ipPreArray[last_pre - 1];
		}

		if (cpP[last_pre + 1 - 1] == cpP[i - 1])
		{
			last_pre = last_pre + 1;
		}
		ipPreArray[i - 1] = last_pre;
	}

	return ipPreArray;

}

void KMPSearcher(char * cpMain, char * cpSub, int iLenMain, int iLenSub)
{
	int i;
	int iMatcherNum;
	int * ipPre;

	ipPre = BuildPreFunction(cpSub, iLenSub);

	iMatcherNum = 0;
	for(i = 0; i < iLenMain; i++)
	{
		while(iMatcherNum > 0 && cpMain[i] != cpSub[iMatcherNum - 1 + 1])
		{
			iMatcherNum = ipPre[iMatcherNum - 1];
		}

		if (cpMain[i] == cpSub[iMatcherNum - 1 + 1])
		{
			iMatcherNum++;
		}

		if(iMatcherNum == iLenSub)
		{
			printf("Get it %s \r\n", cpMain + i - iMatcherNum + 1);
			iMatcherNum = ipPre[iMatcherNum - 1];
		}
	}

	free(ipPre);
}

int main()
{
	char *cpA = "i am a good boy,i like programmingprograming,but i have leaved it for a moment time. programm, programmingprograming";
	char *cpB = "programmingprograming";

	KMPSearcher(cpA, cpB, strlen(cpA), strlen(cpB));
	return 0;
}

