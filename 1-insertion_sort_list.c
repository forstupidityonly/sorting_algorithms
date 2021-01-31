#include "sort.h"
/**
 * switcher - helper
 * @a: the first val
 * @b: the second val
 * Return: no 
 */
void switcher(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}
/**
 * insertion_sort_list - sort linked list with insurtion
 * @list: the list
 * Return: no
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if(!(list && *list && (*list)->next))
		return;
	a = (*list)->next;
	while (a)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				switcher(b->prev, b);
				if (!b->prev)
				{
					*list = b;
				}
				print_list(*list);
			}
			else
				b = b->prev;
		}
	}
}
