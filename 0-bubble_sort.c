#include "sort.h"
/**
 * bubble_sort - fct that swap integers according final ascending orders
 * @array: array of integers to sort
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size != 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		print_array(array, size);

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];

				array[j + 1] = temp;
			}
		}
	}
}
