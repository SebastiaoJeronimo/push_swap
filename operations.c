/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:13:24 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 07:04:18 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief performs the reverse rotate operation on both stacks
*/
int	rev_rotate_both(t_list **stack_a, t_list **stack_b)
{
	return (rev_rotate(stack_a) && rev_rotate(stack_b));
}

/**
 * @brief performs the rotate operation on both stacks
*/
int	rotate_both(t_list **stack_a, t_list **stack_b)
{
	return (rotate(stack_a) && rotate(stack_b));
}

/**
 * @brief performs the swap operation on both stacks
*/
int	swap_both(t_list **stack_a, t_list **stack_b)
{
	return (swap(stack_a) && swap(stack_b));
}

/**
 * @brief executes the selected rotate/rev rotate operation 
*/
int	exec_rotate(char *ptr, t_list **stack_a, t_list **stack_b, int size)
{
	if (!ft_strncmp("ra", ptr, size))
		return (rotate(stack_a));
	if (!ft_strncmp("rb", ptr, size))
		return (rotate(stack_b));
	if (!ft_strncmp("rr", ptr, size))
		return (rotate_both(stack_a, stack_b));
	if (!ft_strncmp("rra", ptr, size))
		return (rev_rotate(stack_a));
	if (!ft_strncmp("rrb", ptr, size))
		return (rev_rotate(stack_b));
	if (!ft_strncmp("rrr", ptr, size))
		return (rev_rotate_both(stack_a, stack_b));
	return (0);
}

/**
 * @brief executes the move indicated by the string ptr 
 * if sucessful prints the move
*/
void	execute_move(char *ptr, t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	sucess;

	size = ft_strlen(ptr);
	if (ptr[0] == 'r')
		sucess = exec_rotate(ptr, stack_a, stack_b, size);
	if (!ft_strncmp("sa", ptr, size))
		sucess = swap(stack_a);
	if (!ft_strncmp("sb", ptr, size))
		sucess = swap(stack_b);
	if (!ft_strncmp("ss", ptr, size))
		sucess = swap_both(stack_a, stack_b);
	if (!ft_strncmp("pa", ptr, size))
		sucess = push(stack_b, stack_a);
	if (!ft_strncmp("pb", ptr, size))
		sucess = push(stack_a, stack_b);
	if (sucess)
	{
		write (1, ptr, size);
		write (1, "\n", 1);
	}
}
