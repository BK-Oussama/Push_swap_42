
#include "push_swap.h"

void push(t_list **head, int value)
{
    if (head == NULL)
    {
        return;
        exit(1); //
    }
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return;
    
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
    printf("%d\n", new_node->data);
}
int stack_is_empty(t_list **head)
{
    if (*head == NULL)
    return -1;
    else
        return 0;
}

int pop(t_list **head)
{
    if (stack_is_empty(&head))
    {
        return -1;
        exit(1); // handle it as you like!
    }   

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