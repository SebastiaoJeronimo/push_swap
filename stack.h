/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:51:11 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/15 22:43:03 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "list.h"

//stack_push.c
int	push(t_list **stack_1, t_list **stack_2);
int	push_elements(t_list *stack); //to put all the elements in the stack a

//stack_reverse_rotate.c
int	rev_rotate(t_list **stack);
int	rev_rotate_both(t_list *stack);

//stack_rotate.c
int	rotate(t_list **stack);
int	rotate_both(t_list *stack);

//stack_swap.c
int	swap (t_list	**stack);
int	swap_both(t_list *stack);

#endif