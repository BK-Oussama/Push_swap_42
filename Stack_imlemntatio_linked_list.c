
#include "push_swap.h"

// void swap_stack_a();
// void swap_stack_b();
// void swap_both_stack();
// void push_stack_a();
// void push_stack_b();
// void rotate_stack_a();
// void rotate_stack_b();
// void rotate_both_stack();
// void reverse_rotate_stack_a(); 
// void reverse_rotate_stack_b();
// void reverse_rotate_both_stack();
// for the function that the the operation for both stack at the same time, i can use them both!
// peek();
// print_stack() // this function print all elemnt in a stack.
// stack_size();
void push(t_list **head, int value)
{
    // if (head == NULL)
    // {
        // return;
        // exit(1); //
    // }
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
        if (*head == NULL || head == NULL)
        return  1;
        else
            return 0;
    }

int pop(t_list **head)
{
    if (stack_is_empty(head))
    {
        printf("Stack Underflow\n");
        return 1;
        // exit(1); // handle This as it should!
    }   

    t_list *tmp;
    int value;

    tmp = *head;
    value = tmp->data;
    *head = (*head)->next;
    free (tmp);
    printf("Poped Value: %d\n", value);
    return (value);
}

int main()
{
    t_list *head = NULL;

    push(&head, 4);
    push(&head, 3);
    pop(&head);
    pop(&head);
    pop(&head);

    return 0;

}