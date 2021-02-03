#include "sort.h"
/**
 * 
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
 * 
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
 * 
 */
void help_sort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = lomuto(array, size, low, high);
		help_sort(array, size, low, pi -1);
		help_sort(array, size, pi + 1, high);
	}
}
/**
 * 
 */
void quick_sort(int *array, size_t size)
{
	
	if (!array || size < 2)
		return;
	help_sort(array, size, 0, size - 1);
}
