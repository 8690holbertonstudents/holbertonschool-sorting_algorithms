#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array passed from main to sort
 * @size: size of the array
 * Return: array sorted
 */
void quick_sort(int *array, size_t size);
{
	size_t i, j, l_id = 0, h_id, piv;

	h_id = size - 1;
	piv = array[h_id];
	i = l_id - 1;
	j = l_id;

	while (j <= h_id)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_val(array[i], array[j]);
		}
		j++;
	}
	swap_val(array[i + 1], array[h_id]);

	piv = (i + 1);

	if (l_id < h_id)
	{
		quick_sort(array, l_id, piv - 1);
		quick_sort(array, piv + 1, h_id);
	}
}

/**
 * swap_val - function that swap 2 values
 * @x: 1st value
 * @y: 2nd value
 * Return: nothing
 */
void swap_val(int x, int y)
{
	int t_array;

	t_array = x;
	x = y;
	y = t_array;
}


