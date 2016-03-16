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

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

bool checkValidDate(char *str)
{
	int date, month,year;
	month = str[4] - '0'*+(str[3] - '0') * 10;
	date = str[1] - '0'*+(str[0] - '0') * 10;
	year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');

	if ((date > 31)&&(date<=0))return false;
	if ((month > 12)&&(month<=0))return false;
	if (year < 0)return false;
	if (date >= 29)
	{
		if (date == 29)
		{
			if ((month == 2) && (year % 4 == 0))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (date == 30)
		{
			if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
				return true;
			else
				return false;
		}
	
	}
	return true;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {

	if (!checkValidDate(date))
	{
		return -1;
	}

	int input_date, input_month, input_year,trans_date,trans_month,trans_year;

	input_month = date[4] - '0'+(date[3] - '0') * 10;
	input_date = date[1] - '0'+(date[0] - '0') * 10;
	input_year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

	int i;

	for (i = 0; i < len; i++)
	{
		if (!checkValidDate(Arr[i].date))
		{
			return -1;
		}

		trans_date = Arr[i].date[1] - '0' + (Arr[i].date[0] - '0') * 10;
		trans_month = Arr[i].date[4] - '0' + (Arr[i].date[3] - '0') * 10;
		trans_year = (Arr[i].date[6] - '0') * 1000 + (Arr[i].date[7] - '0') * 100 + (Arr[i].date[8] - '0') * 10 + (Arr[i].date[9] - '0');


		if ((trans_year >= input_year) && (trans_month >= input_month) && (trans_date>=input_date))
		{
			if ((trans_date == input_date) && (trans_month == input_month) && (trans_year == input_year))
			{
				while ((trans_date == input_date) && (trans_month == input_month) && (trans_year == input_year)&&(i<len))
				{
					i++;
					trans_date = Arr[i].date[1] - '0' + (Arr[i].date[0] - '0') * 10;
					trans_month = Arr[i].date[4] - '0' + (Arr[i].date[3] - '0') * 10;
					trans_year = (Arr[i].date[6] - '0') * 1000 + (Arr[i].date[7] - '0') * 100 + (Arr[i].date[8] - '0') * 10 + (Arr[i].date[9] - '0');
				}
				i--;
				return len - (i + 1);
			}
			else
			{
				return len - i;
			}
		}
	}


	return 0;
}
