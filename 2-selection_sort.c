#include "sort.h"
/**
 * switcher - helper
 * @a: the array[min]
 * @b: the array[itr]
 * Return: no
 */
void switcher(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - splits array into two and sorts
 * @array: the array
 * @size: the size of said array
 * Return: no
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int itr, jtr, min;

	if (!array || size < 2)
		return;
	for (itr = 0; itr < size - 1; itr++)
	{
		min = itr;
		for (jtr = itr; jtr < size; jtr++)
		{
			if (array[jtr] < array[min])
				min = jtr;
		}
		switcher(&array[min], &array[itr]);
		if (min != itr)
			print_array(array, size);
	}
}
