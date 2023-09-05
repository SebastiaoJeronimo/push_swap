/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:05:39 by scosta-j          #+#    #+#             */
/*   Updated: 2023/08/22 22:56:49 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Function to print an error message to stderr.
 */
void	print_error(char *msg, t_list **head)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_list(head);
}

/**
 * @brief recursive function that reads all the input and places the respective
 * numbers on an interger list implemented with linked lists
 */
void	atoi_list(char *str, t_list **head)
{
	long long	sig;
	long long	number;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 0)
		return ;
	sig = (*str != '-') - (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	number = 0;
	if (*str == 0)
		print_error("Error", head);
	while (*str >= '0' && *str <= '9')
		number = (number * 10) + (*str++ - '0');
	if (number > INT_MAX || number < INT_MIN)
		print_error("Error", head);
	ft_lstadd_back(head, ft_lstnew(number * sig));
	if ((*str == ' ' || *str == '\t'))
		atoi_list(str, head);
	else if (*str)
		print_error("Error", head);
}

/**
 * //return something maybe not with the exit() function
 * @brief sees if there exists arguments
 * also checks if the arguments are a series of empty strings
 */
void	check_arguments(int argc, char **argv)
{
	int	i;
	int	j;
	int	not_empty;

	i = 1;
	not_empty = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && argv[i][j] != '\t')
				not_empty = 1;
			j++;
		}
		i++;
	}
	if (!not_empty || argc < 2)
	{
		write(1, "\n", 1);
		exit(0);
	}
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

	check_arguments(argc, argv);
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
		atoi_list(argv[i++], &a);
	check_list(&a);
	start_sorting(&a, &b);
	free_list(&a);
}

/**
 *  LIST OF THINGS
 *
 * 1 - PARSING
 * 	FREE THE LIST IF SOMETHING GOES WRONG 		 //DONE
 * 	CHECK DUPLICATED NUMBERS					 //DONE
 * 	EMPTY STRING							 	 //DONE
 * 	CHECK IF ITS ALREADY ORDERED				 //DONE
 * 	DO I HAVE TO SEE THE MAX INT AND THE MIN INT //DONE
 *
 * 2 - MOVES
 * 	DO THE TWO STACK MOVES						 //DONE
 * 	PRINT THE ACTUAL MOVES IN THE SHELL			 //DONE
 *
 * 3 - ALGORITHM                     
 * 	RADIX											
 * 	indexar os numeros 							 //DONE
 *  void sort(t_list **stack_a, t_list **stack_b)	
 * 	hardcoded para os numeros pequenos			 //DONE
 * 
 * 
 * 4 - MAKEFILE
 * 	PUT THE SOURCE FILES						//DONE
 * 	AND SEE THAT RELINK STUFF					//DONE
 * 
 * 5 - README
 * 
 * 6 - CLEAN CODE 
 * 	NORM 
 * 	REMOVE printf
 * 	write stderr
 */