#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "read.h"

void bubble_sort (student *array,
                  int length)
{
	int idx = 0, cur_length, max_length = length - 1;
	for (cur_length = max_length; cur_length > 0; cur_length--)
	  {
		for (idx = 0; idx < cur_length; idx++)
		  {
			if (array[idx + 1] < array[idx])
			  {
				array[idx].swap (array[idx + 1]);
			  }
		  }
	  }
}
