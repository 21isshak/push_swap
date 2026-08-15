/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:02:37 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:39 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

static void	calculate_price(t_stack *b)
{
	int	temp;

	b->p_mode = 0;
	b->p_price = ft_max(b->position, b->target->position) + 1;
	temp = ft_max(b->totop_rr, b->target->totop_rr) + 1;
	if (b->p_price > temp)
	{
		b->p_price = temp;
		b->p_mode = 1;
	}
	temp = b->target->position + b->totop_rr + 1;
	if (b->p_price > temp)
	{
		b->p_price = temp;
		b->p_mode = 2;
	}
	temp = b->target->totop_rr + b->position + 1;
	if (b->p_price > temp)
	{
		b->p_price = temp;
		b->p_mode = 3;
	}
}

static t_stack	*get_cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b)
	{
		calculate_price(b);
		if (b->p_price <= cheapest->p_price)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

static void	pushhelper(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	p;

	p = 1;
	while (p < cheap->p_price)
	{
		if (cheap->p_mode == 0)
		{
			if (cheap->position - p >= 0 && cheap->target->position - p >= 0)
				rr(a, b);
			else if (cheap->target->position - p >= 0)
				ra_rb(a, 1, 1);
			else
				ra_rb(b, 1, 0);
		}
		else
		{
			if (cheap->totop_rr - p >= 0 && cheap->target->totop_rr - p >= 0)
				rrr(a, b);
			else if (cheap->target->totop_rr - p >= 0)
				rra_rrb(a, 1, 1);
			else
				rra_rrb(b, 1, 0);
		}
		p++;
	}
}

void	push_it(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*b);
	if (cheap->p_mode < 2)
		pushhelper(a, b, cheap);
	if (cheap->p_mode == 2)
	{
		while (cheap->target->position-- > 0)
			ra_rb(a, 1, 1);
		while (cheap->totop_rr-- > 0)
			rra_rrb(b, 1, 0);
	}
	else if (cheap->p_mode == 3)
	{
		while (cheap->target->totop_rr-- > 0)
			rra_rrb(a, 1, 1);
		while (cheap->position-- > 0)
			ra_rb(b, 1, 0);
	}
	pa_pb(b, a, 1);
}
