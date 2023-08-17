#include "stack.h"


/**
 * @brief takes a element from stack1 (pop) and puts in the  stack2 (push)
 * 
 * @param stack_1 stack which the element is going to be removed (pop)
 * @param stack_2 stack which the element is going to be pushed (push)
 * @returns 1 if sucessfull and 0 if not succesful 
 * its not sucessful if the 1 stack is empty
 */
int	push(t_list **stack_1, t_list **stack_2)
{
    t_list *head_1;

    if (!*stack_1)
        return (0); //or NULL
    head_1 = *stack_1;
    *stack_1 = (*stack_1)->next;
    head_1->next = *stack_2;
    *stack_2 = head_1;
    return (1);
    //print the operation after maybe
}

/**
 * @brief swaps the first two elements of the stack
 * 
 * @param stack the stack that we are going to swap the first two elements
 * @return int 1 if sucessful 0 if stack empty or has one element
 */
int	swap (t_list	**stack)
{
    t_list *first;
    t_list *second;
    t_list *third;

    if (!*stack || !(*stack)->next)
        return (0);
    first = *stack;
    second = (*stack)->next;
    third = second->next;
    first->next = third;
    second->next = first;
    *stack = second; //update the reference of the head of the stack
    return (1);
}

/**
 * @brief rotates the stack the first element becomes the last one
 * 
 * @param stack stack in which the operation is going to be performed
 * @return int 1 if sucessfull 0 if empty or has one element
 */
int	rotate(t_list **stack)
{
    t_list *first;
    t_list *second;
    t_list *last;

    if (!*stack || !(*stack)->next)
        return (0);
    first = *stack;
    second = first->next;
    last = *stack;
    while (last->next)
        last = last->next;
    first->next = NULL;
    last->next = first;
    *stack = second;
    return (1);
}

/**
 * @brief reverse rotate the last element of the stack becomes the first one
 * 
 * @param stack the stack in which the operation is going to be performed
 * @return int 1 if is sucessfull 0 if its not
 */
int	rev_rotate(t_list **stack)
{
    t_list *first;
    t_list *last;
    t_list *new_last;
    if (!*stack || !(*stack)->next)
        return (0);
    first = *stack;
    last = *stack;
    while (last->next)
    {
        new_last = last;
        last = last->next;
    }
    new_last->next = NULL;
    last->next = first;
    *stack = last;
    return (1);
}