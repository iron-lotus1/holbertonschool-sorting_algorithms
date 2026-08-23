#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions a subset of an array using Lomuto scheme.
 * @array: The array of integers.
 * @size: Total size of the array (used for printing).
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition (the pivot).
 *
 * Return: The final partition index of the pivot.
 */
size_t lomuto_partition(int *array, size_t size, ssize_t left, ssize_t right)
{
	int pivot = array[right];
	ssize_t i = left - 1, j;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		swap_ints(&array[i + 1], &array[right]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - Recursively sorts an array subset using Quick sort.
 * @array: The array of integers.
 * @size: Total size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 */
void lomuto_sort(int *array, size_t size, ssize_t left, ssize_t right)
{
	if (left < right)
	{
		size_t p_idx = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, (ssize_t)p_idx - 1);
		lomuto_sort(array, size, (ssize_t)p_idx + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, (ssize_t)size - 1);
}
