/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:48:39 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 19:46:28 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include <limits.h>

//main.c
int		check_argumnets(int argc, char **argv);
void	print_error(char *msg, t_list **head);

//algorithms.c 
void	start_sorting(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	fill_index(t_list **stack);

//sort.c
void	small_sort(t_list **stack_a, t_list **stack_b, int size);
void	sort_3(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **list);

#endif