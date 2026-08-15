/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:47:35 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:01:53 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *stack, bool printit, bool sa)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	if (printit)
	{
		if (sa)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a, 0, 0);
	sa_sb(b, 0, 0);
	ft_printf("ss\n");
}

void	pa_pb(t_stack **tar, t_stack **dest, bool pa)
{
	t_stack	*target;

	if (tar == NULL || dest == NULL)
		return ;
	target = *tar;
	*tar = target->next;
	if (*tar != NULL)
		target->next->prev = NULL;
	target->next = *dest;
	if (*dest != NULL)
		target->next->prev = target;
	*dest = target;
	if (pa)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
