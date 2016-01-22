/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	int i, num, j, count = 0, flag = 0;
	for (i = 0; i < len; i++)
	{
		num = A[i];
		count = 0;
		for (j = 0; j < len; j++)
		{
			if (A[j] == num)
				count++;
		}
		if (count == 1)
		{
			flag = 1;
			return A[i];
		}
	}
	if (flag == 0)
		return NULL;

}