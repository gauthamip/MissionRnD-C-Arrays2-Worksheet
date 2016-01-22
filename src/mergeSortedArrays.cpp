/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare_dates(char d1[], char d2[]);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0, temp;
	struct transaction *result = (struct transaction*)malloc((ALen+BLen)*sizeof(struct transaction));
	while (1)
	{
		temp = compare_dates(A[i].date, B[j].date);
		if (temp == -1)
		{
			result[k] = A[i];
			k++; i++;
		}
		else if (temp == 0)
		{
			result[k] = A[i];
			i++; k++;
			result[k] = B[j];
			j++; k++;
		}
		else
		{
			result[k] = B[j];
			j++; k++;
		}
		if (i == ALen || j == BLen)
			break;
	}
	while (i != ALen)
	{
		result[k] = A[i];
		k++; i++;
	}
	while (j != BLen)
	{
		result[k] = B[j];
		k++; j++;
	}
	return result;
}
int compare_dates(char d1[], char d2[])
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
				return 0;
			else if (dd1 > dd2)
				return 1;
		}
		else if (m1 > m2)
		{
			return 1;
		}

	}
	else if (y1 > y2)
	{
		return 1;
	}
	else
	{
		return -1;

	}
}