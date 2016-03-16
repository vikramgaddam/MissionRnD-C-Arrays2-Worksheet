/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
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

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if ((A == NULL) || (B == NULL))return NULL;

	int i = 0, j = 0,res_index=0;

	struct transaction *res;

	if (ALen<BLen)
	 res = (struct transaction*)malloc(sizeof(struct transaction)*ALen);
	else
	{
		res = (struct transaction*)malloc(sizeof(struct transaction)*BLen);

	}
	

	int input1_date, input1_month, input1_year, input2_date, input2_month, input2_year;

	while ((i < ALen) && (j < BLen))
	{
		input1_date = A[i].date[1] - '0' + (A[i].date[0] - '0') * 10;
		input1_month = A[i].date[4] - '0' + (A[i].date[3] - '0')*10;
		input1_year = (A[i].date[6] - '0') * 1000 + (A[i].date[7] - '0') * 100 + (A[i].date[8] - '0') * 10 + (A[i].date[9] - '0');

		input2_date = B[j].date[1] - '0' + (B[j].date[0] - '0') * 10;
		input2_month = B[j].date[4] - '0' + (B[i].date[3] - '0')*10;
		input2_year = (B[j].date[6] - '0') * 1000 + (B[j].date[7] - '0') * 100 + (B[j].date[8] - '0') * 10 + (B[j].date[9] - '0');

		if ((input1_date == input2_date) && (input1_month == input2_month) && (input1_year == input2_year))
		{
			res[res_index] = A[i];
			res_index++;
			i++;
			j++;
		}
		if (input1_year < input2_year)
		{
			i++;
		}
		else
		{
			if (input2_year > input1_year)
			{
				j++;
			}
			else
			{
				if (input1_month > input2_month)
				{
					i++;
				}
				else
				{
					if (input2_month > input1_month)
					{
						j++;
					}
					else
					{
						if (input1_date > input2_date)
						{
							i++;
						}
						else
						{
							if (input2_date > input1_date)
							{
								j++;
							}
						}
					}
				}
			}
		}


	}

	if (res_index == 0)
		return 0;
	return res;


}