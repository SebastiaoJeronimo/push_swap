/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:18:55 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/15 23:13:39 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/**
 * @brief adds a node after the last node of the list
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (tmp_lst->next != NULL)
	{
		tmp_lst = tmp_lst->next;
	}
	tmp_lst->next = new;
}

/**
 * @brief adds a node before the first node of the list
 * The pointer to the list is now pointing to the new beggining of the list
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/**
 * @brief initializes a new list with the content that is passed on the parameter
*/
t_list	*ft_lstnew(int content)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->data = content;
	l->next = NULL;
	return (l);
}
