/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:18:06 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 06:46:31 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief checks if there are duplicates on the argument list
*/
void	check_duplicates(t_list **list)
{
	t_list	*head;
	t_list	*aux;

	head = *list;
	while (head->next) 
	{
		aux = head->next;
		while (aux) 
		{
			if (head->data == aux->data) 
				print_error("Error", list);
			aux = aux->next;
		}
		head = head->next;
	}
}

/**
 * @brief checks if the input is already ordered 
 * if it is returns "no need to sort or Error"
*/
void	check_ordered(t_list **list)
{
	t_list	*head;
	int		sorted;

	sorted = 1;
	head = *list;
	while (head->next)
	{
		if (head->data > (head->next)->data)
			sorted = 0;
		head = head->next;
	}
	if (sorted)
	{
		write (1, "\n", 1);
		free_list(list);
	}
}

/**
 * checks if the interger list has duplicates
 * checks if the interger list is already ordered 
*/
void	check_list(t_list **list)
{
	check_duplicates(list);
	check_ordered(list);
}
