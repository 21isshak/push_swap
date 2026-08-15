/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:11:26 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:52 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stackposition(t_stack *a)
{
	int	i;

	i = -1;
	while (a)
	{
		a = a->prev;
		i++;
	}
	return (i);
}

static void	set_top_it_price(t_stack *a, t_stack *b, bool set_b)
{
	int	len;

	len = ft_stacklength(a);
	while (a)
	{
		a->position = ft_stackposition(a);
		a->totop_rr = len - a->position;
		if (a->prev == NULL)
			a->totop_rr = 0;
		a = a->next;
	}
	if (set_b)
		set_top_it_price(b, NULL, 0);
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*max;

	if (!a || !b)
		return ;
	max = ft_maxstack(a);
	while (b)
	{
		b->target = max;
		temp = a;
		while (temp)
		{
			if (b->value < temp->value && temp->value < b->target->value)
				b->target = temp;
			temp = temp->next;
		}
		b = b->next;
	}
}

void	final_setittop(t_stack **a, t_stack *max)
{
	int		price;
	t_stack	*min;

	min = max->next;
	if (min->position < min->totop_rr)
	{
		price = min->position;
		while (price-- > 0)
			ra_rb(a, 1, 1);
	}
	else
	{
		price = min->totop_rr;
		while (price-- > 0)
			rra_rrb(a, 1, 1);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*max;

	len = ft_stacklength(*a);
	max = ft_maxstack(*a);
	while (len > 3)
	{
		if (*a == max)
		{
			ra_rb(a, 1, 1);
			continue ;
		}
		pa_pb(a, b, 0);
		len--;
	}
	ft_tiny_sort(a);
	while (*b != NULL)
	{
		set_top_it_price(*a, *b, 1);
		set_target(*a, *b);
		push_it(a, b);
	}
	set_top_it_price(*a, NULL, 0);
	if (!ft_stacksorted(*a))
		final_setittop(a, max);
}
