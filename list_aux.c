/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:18:55 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 06:34:50 by scosta-j         ###   ########.fr       */
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

/**
 * @brief returns the size of the list
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp_lst;

	i = 0;
	temp_lst = lst;
	while (temp_lst != NULL)
	{
		temp_lst = temp_lst->next;
		i++;
	}
	return (i);
}

/**
 * @brief Function to free a linked list. ends the progam after that
 */
void	free_list(t_list **head)
{
	t_list	*l_temp;

	while (*head)
	{
		l_temp = (*head)->next;
		free(*head);
		*head = l_temp;
	}
	exit(0);
}
