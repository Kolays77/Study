#include <stdio.h>
#include "head.h"

int main(void)
{
	const char *name1 = "a.txt", *name2 = "b.txt";
	int res = check(name1, name2);
	switch (res)
	{
		case (-22):
		{
			printf("%s is empty\n", name2);
			break;
		}
		case (-21):
		{
			printf("%s is empty\n", name1);
			break;
		}
		case (-11):
		{
			printf("Cannot open %s\n", name1);
			break;
		}
		case (-12):
		{
			printf("Cannot open %s\n", name2);
			break;
		}
		case (-3):
		{
			printf("There is not enough elements in %s\n", name1);
			break;
		}
		case (-41):
		{
			printf("Cannot read %s\n", name1);
			break;
		}
		case (-42):
		{
			printf("Cannot read %s\n", name2);
			break;
		}
		case (0):
		{
			printf("Sequences don't satisfy the condition\n");
			break;
		}
		case (1):
		{
			printf("Sequences satisfy the condition\n");
			break;
		}
		default:
		{
			printf("Unknown Error\n");
		}
	}
	return 0;
}
