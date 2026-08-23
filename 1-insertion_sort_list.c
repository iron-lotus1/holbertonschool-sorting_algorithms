#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: Pointer to the first node to swap (comes before node2)
 * @node2: Pointer to the second node to swap (comes after node1)
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next)
        node2->next->prev = node1;

    node2->prev = node1->prev;
    node1->next = node2->next;
    
    node2->next = node1;
    node1->prev = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion sort.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *insert_node;

    if (!list || !*list || !(*list)->next)
        return;

    curr = (*list)->next;
    while (curr)
    {
        insert_node = curr;
        curr = curr->next; /* Save next node before potential swaps shift positions */

        while (insert_node->prev && insert_node->n < insert_node->prev->n)
        {
            swap_nodes(list, insert_node->prev, insert_node);
            print_list(*list);
        }
    }
}
