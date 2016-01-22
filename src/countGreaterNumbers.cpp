/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
int compare(char*, char*);
int date_validity(char*);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0;
	int count = 0;
	if (date_validity(date) == 0)
		return NULL;
	for (i = 0; i < len; i++)
	{
		if (compare(Arr[i].date, date) == 1)
		{
			count++;
		}
	}
	return count;
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
	if (y1 > y2)
	{
		return 1;
	}
	else if (y1 == y2)
	{
		if (m1 > m2)
		{
			return 1;
		}
		else
		{
			if (dd1 > dd2)
				return 1;
		}
	}
	else
		return 0;


}
int date_validity(char *ip)
{
	int dd, mm, yy1, yy2;
	dd = (ip[0] - '0') * 10 + (ip[1] - '0');
	mm = (ip[3] - '0') * 10 + (ip[4] - '0');
	if (mm <= 0 || mm > 12)
	{
		return 0;
	}
	else if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 9 || mm == 11) && (dd <= 0 || dd > 30))
	{
		return 0;
	}
	else if ((mm == 4 || mm == 6 || mm == 8 || mm == 10 || mm == 12) && (dd <= 0 || dd > 31))
	{
		return 0;
	}
	else if (mm == 2 && dd <= 0 || dd > 29)
	{
		return 0;
	}
	return 1;
}
