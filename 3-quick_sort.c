#include "sort.h"

void swap_two_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_two_ints - Swap two integers in an array.
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */
void swap_two_ints(int *a, int *b)
{
	int buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

/**
 * lomuto_partition - Order an array of integers according to the lomuto partition scheme 
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above_pivot, below_pivot;

	pivot = array + right;
	for (above_pivot = below_pivot = left; below_pivot < right; below_pivot++)
	{
		if (array[below_pivot] < *pivot)
		{
			if (above_pivot < below_pivot)
			{
				swap_two_ints(array + below_pivot, array + above_pivot);
				print_array(array, size);
			}
			above_pivot++;
		}
	}

	if (array[above_pivot] > *pivot)
	{
		swap_two_ints(array + above_pivot, pivot);
		print_array(array, size);
	}

	return (above_pivot);
}

/**
 * lomuto_sort - Implement the quicksort algorithm
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int list;

	if (right - left > 0)
	{
		list = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, list - 1);
		lomuto_sort(array, size, list + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using the quicksort algorithm
 * @array: An array of integers.
 * @size: The size of the array
 * Description: Uses the Lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}