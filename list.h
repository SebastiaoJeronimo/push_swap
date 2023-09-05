/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:49:17 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 06:35:16 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list	t_list;

struct s_list
{
	int				data;
	int				index;
	t_list			*next;
};

//list_aux.c
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int v);
int		ft_lstsize(t_list *lst);
void	free_list(t_list **head);

//list_checker.c
void	check_list(t_list **list);
void	check_duplicates(t_list **list);

#endif