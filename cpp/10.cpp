int rewrite_array(double *array, int length, double x)
{
	int idx, number_of_less = 0;
	for (idx = 0; idx < length; idx++)
	{
		if (array[idx] < x)
		{
			number_of_less++;
			continue;
		}
		array[idx - number_of_less] = array[idx];
	}
	for (idx = length - number_of_less; idx < length; idx++)
	{
		array[idx] = 0;
	}
	return length - number_of_less;	
}