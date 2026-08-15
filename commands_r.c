/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:04:41 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:04:42 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack **stack, bool printit, bool ra)
{
	t_stack	*last;
	t_stack	*first;

	if (stack == NULL || *stack == NULL)
		return ;
	last = ft_lastnode(*stack);
	first = *stack;
	first->next->prev = NULL;
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (printit)
	{
		if (ra)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra_rb(a, 0, 0);
	ra_rb(b, 0, 0);
	ft_printf("rr\n");
}

void	rra_rrb(t_stack **stack, bool printit, bool rra)
{
	t_stack	*last;
	t_stack	*first;

	if (stack == NULL || *stack == NULL)
		return ;
	last = ft_lastnode(*stack);
	first = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	if (printit)
	{
		if (rra)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a, 0, 0);
	rra_rrb(b, 0, 0);
	ft_printf("rrr\n");
}
