/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:51:11 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 18:08:33 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "list.h"
# include <stdlib.h>

//stack_operations.c
int		push(t_list **stack_1, t_list **stack_2);
int		rev_rotate(t_list **stack);
int		rotate(t_list **stack);
int		swap(t_list	**stack);

//operations.c
int		rev_rotate_both(t_list **stack_a, t_list **stack_b);
int		rotate_both(t_list **stack_a, t_list **stack_b);
int		swap_both(t_list **stack_a, t_list **stack_b);
void	execute_move(char *ptr, t_list **stack_a, t_list **stack_b);
int		exec_rotate(char *ptr, t_list **stack_a, t_list **stack_b, int size);

//utils.c 
int		ft_strlen(const char *ptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif