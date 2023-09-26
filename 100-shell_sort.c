#include "sort.h"

/**
 * swaps_two_ints - Swap two integers of array
 * @a: The first integer
 * @b: The second integer
 */
void swaps_two_ints(int *a, int *b)
{
	int buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 * using the shell sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Use the Knuth sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swaps_two_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}