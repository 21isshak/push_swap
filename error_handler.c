/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:34:14 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:00 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_avfree(char **av)
{
	int	i;

	i = 0;
	if (av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	ft_stackfree(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temporary;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temporary = current->next;
		free(current);
		current = temporary;
	}
	*stack = NULL;
}

void	ft_error(t_stack **stack, char **av, bool flag_av)
{
	ft_stackfree(stack);
	if (flag_av)
		ft_avfree(av);
	write(2, "ERROR\n", 6);
	exit (1);
}
