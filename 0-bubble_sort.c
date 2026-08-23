#include "sort.h"

/**
 * bubble_sort - sort array using bubble sort
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	if (size <= 0)
		return;

	i = 0;

	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
			j = j + 1;
		}
		i = i + 1;
	}
}