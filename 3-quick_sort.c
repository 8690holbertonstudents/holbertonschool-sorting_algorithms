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
	int p = size - 1;

	if (array == NULL || size < 2)
		return;

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
	int pi = 0;

	if (low < high)
	{
		pi = part_array(array, low, high, size);

		quick_sort_help(array, low, pi - 1, size);
		quick_sort_help(array, pi + 1, high, size);
	}
}

/**
 * part_array - divide function to separate around pivot
 * @array: array to sort
 * @low: low index value
 * @high: high index value
 * @size: size of the array
 * Return: pivot index to quick_sort_help
 */
int part_array(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j = low;
	int temp;

	while (j <= high)
	{
		if (array[j] < array[high])
		{
			i++;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}
