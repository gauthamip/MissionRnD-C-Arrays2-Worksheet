/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<string.h>
#include<stdio.h>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char[], char[]);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0;
	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction));
	struct transaction *output = (struct transaction *)malloc(sizeof(struct transaction));
	char date[11];
	int flag = 0;
	for (i = 0; i < ALen; i++)
	{
		strcpy(date, A[i].date);
		for (j = 0; j < BLen; j++)
		{
			if (compare(date, B[j].date) == 1)
			{
				result[k] = B[j];
				k++;
				flag = 1;
			}

		}
	}
	if (flag == 0)
		return NULL;

	return result;

}
int compare(char d1[], char d2[])
{
	int dd1, dd2, m1, m2, y1, y2;
	dd1 = (d1[0] - '0') * 10 + (d1[1] - '0');
	dd2 = (d2[0] - '0') * 10 + (d2[1] - '0');
	m1 = (d1[3] - '0') * 10 + (d1[4] - '0');
	m2 = (d2[3] - '0') * 10 + (d2[4] - '0');
	y1 = (d1[6] - '0') * 1000 + (d1[7] - '0') * 100 + (d1[8] - '0') * 10 + (d1[9] - '0');
	y2 = (d2[6] - '0') * 1000 + (d2[7] - '0') * 100 + (d2[8] - '0') * 10 + (d2[9] - '0');
	if (y1 == y2)
	{
		if (m1 == m2)
		{
			if (dd1 == dd2)
				return 1;
		}

	}
	else
	{
		return 0;

	}
}
