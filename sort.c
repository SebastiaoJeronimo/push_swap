/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:10:16 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 22:51:25 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief checks if a tree element list is sorted
*/
int	is_sorted(t_list **list)
{
	int	first;
	int	second;
	int	third;

	first = (*list)->data;
	second = (*list)->next->data;
	third = (*list)->next->next->data;
	return (first < second && second < third);
}

/**
 * cases 3 numbers optimal performance
 * "2 1 0"	//ra sa     //sim
 * "2 0 1" //ra			//sim
 * //----------
 * "1 2 0" //rra		//sim
 * "1 0 2" //sa			//sim
 * //----------
 * "0 2 1" //rra sa		//sim
*/
void	sort_3(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->data > (*stack_a)->next->data && \
		(*stack_a)->data > (*stack_a)->next->next->data)
	{
		execute_move("ra", stack_a, stack_b);
		if ((*stack_a)->next->data < (*stack_a)->next->next->data \
			&& !is_sorted(stack_a))
			execute_move("sa", stack_a, stack_b);
		return ;
	}
	if (((*stack_a)->data < (*stack_a)->next->data) && \
		((*stack_a)->next->data > (*stack_a)->next->next->data) \
			&& !is_sorted(stack_a))
	{
		execute_move("rra", stack_a, stack_b);
		if ((*stack_a)->next->data < (*stack_a)->next->next->data \
			&& !is_sorted(stack_a))
			execute_move("sa", stack_a, stack_b);
		return ;
	}
	execute_move("sa", stack_a, stack_b);
}

/**
 * sorts five or four numbers
*/
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		barrier;

	size_a = ft_lstsize(*stack_a);
	barrier = 0 + (size_a == 5);
	while (size_a > 3)
	{
		if ((*stack_a)->index <= barrier)
		{
			execute_move("pb", stack_a, stack_b);
			size_a--;
		}
		else 
			execute_move("ra", stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_3(stack_a, stack_b);
	if ((*stack_b)->next && (*stack_b)->data < (*stack_b)->next->data)
		execute_move("sb", stack_a, stack_b);
	size_a = ft_lstsize(*stack_b);
	while (size_a)
	{
		execute_move("pa", stack_a, stack_b);
		size_a--;
	}
}

void	small_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		rotate (stack_a);
		write (1, "ra\n", 3);
	}
	if (size == 3)
		sort_3(stack_a, stack_b);
	if (size > 3 && size <= 5)
		sort_5(stack_a, stack_b);
}
