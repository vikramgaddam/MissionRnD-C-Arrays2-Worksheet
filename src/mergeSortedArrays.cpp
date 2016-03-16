/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if ((A == NULL) || (B == NULL))return NULL;

	struct transaction *res = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));

	int i = 0, j = 0, res_index = 0;

	int input1_date, input1_month, input1_year, input2_date, input2_month, input2_year;

	while ((i < ALen) && (j < BLen))
	{
		input1_date = A[i].date[1] - '0' + (A[i].date[0] - '0') * 10;
		input1_month = A[i].date[4] - '0' + (A[i].date[3] - '0') * 10;
		input1_year = (A[i].date[6] - '0') * 1000 + (A[i].date[7] - '0') * 100 + (A[i].date[8] - '0') * 10 + (A[i].date[9] - '0');

		input2_date = B[j].date[1] - '0' + (B[j].date[0] - '0') * 10;
		input2_month = B[j].date[4] - '0' + (B[j].date[3] - '0') * 10;
		input2_year = (B[j].date[6] - '0') * 1000 + (B[j].date[7] - '0') * 100 + (B[j].date[8] - '0') * 10 + (B[j].date[9] - '0');



		if (input1_year < input2_year)
		{
			res[res_index] = A[i];
			i++;
			res_index++;
		}
		else
		{
			if (input2_year < input1_year)
			{
				res[res_index] = B[j];
				j++;
				res_index++;
			}
			else
			{
				if (input1_month < input2_month)
				{
					res[res_index] = A[i];
					i++;
					res_index++;

				}
				else
				{
					if (input2_month < input1_month)
					{
						res[res_index] = B[j];
						j++;
						res_index++;
					}
					else
					{
						if (input1_date < input2_date)
						{
							res[res_index] = A[i];
							i++;
							res_index++;
						}
						else
						{
							if (input2_date < input1_date)
							{
								res[res_index] = B[j];
								j++;
								res_index++;
							}
							else
							{
								res[res_index] = A[i];
								res_index++;
								res[res_index] = B[j];
								i++;
								j++;
								res_index++;
							}
						}
					}
				}
			}
		}
	}

	if (i <= (ALen-1))
	{
		while (i <= (ALen - 1))
		{
			res[res_index] = A[i];
			i++;
			res_index++;
		}
	}

	if (j <= BLen - 1)
	{
		while (j <= BLen - 1)
		{
			res[res_index] = B[j];
			j++;
			res_index++;
		}
	}
	
	return res;
}