#include "sort.h"
/**
 * switcher - use pointers to change values in big and small
 * @big: the bigger value that needs to "float" to the top
 * @little: the smaller value that "sinks" to the bottom
 * Return: void
 */
void switcher(int *big, int *little)
{
	int temp = *big;
	*big = *little;
	*little = temp;
}
/**
 * bubble_sort - sort array by "floating" large val top, and "sink" little ones
 * @array: the array
 * @size: the size of the array
 * Return: no
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int fake_bool;

	if (!array || !size || size == 0)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		fake_bool = 0;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				switcher(&array[j], &array[j + 1]);
				print_array(array, size);
				fake_bool = 1;
			}
		}
/** if noting was switched its sorted. with this, time complexity goes from */
/** O(n^2) constant to worst case of O(n*n) when array is reverse sorted */

		if (fake_bool == 0)
			break;
	}
}
