#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array passed from main to sort
 * @size: size of the array
 * Return: array sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_id = 0;
	int t_array;

	while (i < (size - 1))
	{
		min_id = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[min_id])
				min_id = j;
			j++;
		}

		if (min_id != i)
		{
			t_array = array[min_id];
			array[min_id] = array[i];
			array[i] = t_array;
			print_array(array, size);
		}

		i++;
	}
}
