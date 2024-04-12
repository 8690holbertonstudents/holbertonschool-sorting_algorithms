#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array passed from main to sort
 * @size: size of the array
 * Return: array sorted
 */
void quick_sort(int *array, size_t size)
{
	int i = 0;
	size_t j;
	int p = size - 1;

	if(array == NULL || size < 2)
		return;

	for (j = 0 ; j < size - 1 ; j++ )
		{
			if (array[j] < array[j + 1])
				j++;
			else
			{
				if (j == size - 1)
					return;
				else
					break;
			}
		}
	quick_sort_help(array, i, p, size);
}

/**
 * quick_sort_help - recursive function to sort
 * each partition create by part_array around pivot
 * @array: array to sort
 * @low: low index value
 * @high: high index value
 * @size: size of array
 * Return: nothing
 */
void quick_sort_help(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = part_array(array, low, high);
		print_array(array, size);

		quick_sort_help(array, low, pi - 1, size);
		quick_sort_help(array, pi + 1, high, size);
	}
}

/**
 * part_array - divide function to separate around pivot
 * @array: array to sort
 * @low: low index value
 * @high: high index value
 * Return: pivot index to quick_sort_help
 */
int part_array(int *array, int low, int high)
{
	int i = low - 1;
	int j = low;

	while (j <= high)
	{
		if (array[j] < array[high])
		{
			i++;
			swap_val(&array[i], &array[j]);
		}
		j++;
	}
	swap_val(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * swap_val - function that swap 2 value of array
 * @x: 1st value
 * @y: 2nd value
 * Return: nothing
 */
void swap_val(int *x, int *y)
{
	int t_array;

	t_array = *x;
	*x = *y;
	*y = t_array;
}
