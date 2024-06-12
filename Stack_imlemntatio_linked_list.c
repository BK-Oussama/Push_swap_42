
#include "push_swap.h"

void push(t_list **head, int value)
{
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return;
    
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
    printf("%d\n", new_node->data);
}

int pop(t_list **head)
{
    if (*head == NULL || head == NULL)
        return -1;

    t_list *tmp;
    int value;

    tmp = *head;
    value = tmp->data;
    *head = (*head)->next;
    free (tmp);
    return (value);
}

int main()
{
    t_list *head = NULL;

    push(&head, 4);
    push(&head, 3);
    return 0;

}