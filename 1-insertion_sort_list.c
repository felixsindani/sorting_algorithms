#include "sort.h"

/**
 * swap_two_intergers - Swaps two integers of array.
 * @a: The first integer
 * @b: The second integer
 */
void swap_two_intergers(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

/**
 * selection_sort - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: print the list after each time you swap two elements
 */
void selection_sort(int *array, size_t size)
{
	int *minimum_int;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum_int = array + i;
		for (j = i + 1; j < size; j++)
			minimum_int = (array[j] < *minimum_int) ? (array + j) : minimum_int;

		if ((array + i) != minimum_int)
		{
			swap_two_intergers(array + i, minimum_int);
			print_array(array, size);
		}
	}
}
