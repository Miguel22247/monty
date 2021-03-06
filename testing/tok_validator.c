#include "monty.h"
/**
 * tok_valid - check if tokenized value is valid to store
 * @tok_num: token after opcode in file
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void tok_valid(char *tok_num, unsigned int line_number)
{
	int i, j, k, neg = 0, num = 0;
	char absolute[1024];

	if (tok_num)
	{
		for (i = 0; tok_num[i] != '\0'; i++)
		{
			if (tok_num[0] == 45)
				neg = 1;
			if ((tok_num[i] < 48 || tok_num[i] > 57) && tok_num[0] != 45)
			{
				fprintf(stderr, "L%i: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		i = 1;
		if (neg == 1)
		{
			while (tok_num[i] != '\0')
			{
				if (tok_num[i] < 48 || tok_num[i] > 57)
				{
					fprintf(stderr, "L%i: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				i++;
			}
			for (j = 1, k = 0; tok_num[j] != '\0'; k++, j++)
			absolute[k] = tok_num[j];
			num = atoi(absolute);
			number = num * -1;
		}
		else
			number = atoi(tok_num);
	}
	else
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}