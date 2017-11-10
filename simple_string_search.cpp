// NaiveStringMatch.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
#include "string.h"

int StrMatcher(char *cpA, char *cpB, int iLen)
{
	int i;

	for (i = 0; i < iLen; i++)
	{
		if(cpA[i] != cpB[i])
		{
			return -1;
		}
	}

	return 0;
}

char * NaiveStringMatch(char * cpMain, char *cpSub, int iLenA, int iLenB)
{
	int i;

	if (NULL == cpMain || NULL == cpSub)
	{
		return NULL;
	}

	for (i = 0; i < iLenA - iLenB + 1; i++)
	{
		if (0 == StrMatcher(cpMain + i, cpSub, iLenB))
		{
			return cpMain + i;
		}
	}

	return NULL;
}

int main()
{
	char * cpA = "Hello,i am so sad";
	char * cpB = "sad";

	char *cpPoint;

	cpPoint = NaiveStringMatch(cpA, cpB, strlen(cpA),  strlen(cpB));

	if(NULL != cpPoint)
	{
		printf("Get it %s", cpPoint);
	}
	else
	{
		printf("Not match");
	}

	return 0;
}

