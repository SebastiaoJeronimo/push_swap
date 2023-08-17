/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:05:39 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/15 23:32:50 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void erro(t_list *head, char *msg)
{
	printf("%s\n", msg); //change for a write
	//put function that clears the list 
	exit(0);
}

void	atoi_list(char *str, t_list **head)
{
	long long	sig;
	long long	number;

	while (*str == ' ' || *str == '\t')
		*str++;
	if (*str == 0)
		return ;
	sig = (*str != '-') - (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	number = 0;
	if (*str == 0)
		erro(*head, "error");
	while (*str >= '0' && *str <= '9')
		number = (number * 10) + (*str++ - '0');
	ft_lstadd_back(head, ft_lstnew(number * sig));
	if ((*str == ' ' || *str == '\t'))
		atoi_list(str, head);
	else if (*str)
		erro(*head, "error");
}

/**
 * //return something
 * @brief starts the checking process to see if the arguments are valid
 * no repetitive arguments 
 * "42" "342" fazer atois e ir comparando ou ir filtrando os caracteres
 * no invalid chars
 * 
*/ 
int	check_arguments(int argc, char **argv)
{
	int	wc;
	if (argc < 2) 
		write(1, "please pass a list of intergers\n", 33);
	return (0);
}

/**
 * check if the arguments ac > 1
 * only intergers
 * numbers cant be duplicated
 * stack b is empty
*/
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		return (write(1, "please pass a list of intergers\n", 33));
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
		atoi_list(argv[i++], &a);
	b = a;
	while (b)
	{
		printf("%i\n", b->data);
		b = b->next;
	}
	
}
