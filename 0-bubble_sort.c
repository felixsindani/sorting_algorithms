#include "sort.h"

/**
 * swap_two_intergers - Swap two integers of array
 * @a: The first integer
 * @b: The second integer
 */
void swap_two_intergers(int *a, int *b)
{
	int buffer_holder;

	buffer_holder = *a;
	*a = *b;
	*b = buffer_holder;
}

/**
 * bubble_sort - Sort an array of integers in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 * Description: Prints the array after each swap operation
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubble_decision = false;

	if (array == NULL || size < 2)
		return;

	while (bubble_decision == false)
	{
		bubble_decision = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_two_intergers(array + i, array + i + 1);
				print_array(array, size);
				bubble_decision = false;
			}
		}
		length--;
	}
}