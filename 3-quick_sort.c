#include "sort.h"
/**
 * switcher - swaps a and b
 * @array: the array
 * @size: size of array
 * @a: first int
 * @b: second
 * Return: no
 */
void switcher(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *b;
		*b = *a;
		*a = temp;
		print_array((const int *)array, size);
	}
}
/**
 * lomuto - the partitioning scheme we use
 * @array: the array
 * @size: the size
 * @low: the low on the partition
 * @high: the high on the partition
 * Return: no
 */
int lomuto(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			switcher(array, size, &array[i], &array[j]);
		}
	}
	switcher(array, size, &array[i + 1], &array[high]);
	return (i + 1);
}
/**
 * help_sort - help sort for quick sort
 * @array: the array
 * @size: the size of array
 * @low: the low point
 * @high: the hight point
 * Retun: no
 */
void help_sort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = lomuto(array, size, low, high);
		help_sort(array, size, low, pi - 1);
		help_sort(array, size, pi + 1, high);
	}
}
/**
 * quick_sort - recursive sorting alg
 * @array: the array
 * @size: the size
 * Return: no
 */
void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;
	help_sort(array, size, 0, size - 1);
}
