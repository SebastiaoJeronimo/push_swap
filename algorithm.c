/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:01 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 22:55:49 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief gives an index starting at zero 
 * according to the incresing order of the number
 * example 1 3 2 : 0 2 1
*/
void	fill_index(t_list **stack)
{
	t_list	*head;
	t_list	*current;
	t_list	*aux;
	int		index;

	head = *stack;
	current = *stack;
	aux = head;
	while (current)
	{
		index = 0;
		while (head)
		{
			if (current->data > head->data)
				index++;
			head = head->next;
		}
		current->index = index;
		current = current->next;
		head = aux;
	}
}

void	start_sorting(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	fill_index(stack_a);
	if (size <= 5)
		small_sort(stack_a, stack_b, size);
	else 
		radix_sort(stack_a, stack_b);
}

/**
 * @brief aplies the radix sort for the two stacks
 * 
 * @param size its the size of the list
 * @param max_num the higest number on the list - 1 beacause offset
 * @param max_bits the max bits of a highest number
*/
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0) 
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index) >> i) & 1) 
				execute_move("ra", stack_a, stack_b);
			else 
				execute_move("pb", stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			execute_move("pa", stack_a, stack_b);
		i++;
	}
}
