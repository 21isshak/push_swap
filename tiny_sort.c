/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:48:02 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:03:14 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_maxstack(t_stack *a)
{
	t_stack	*max;

	max = a;
	a = a->next;
	while (a)
	{
		if (max->value < a->value)
			max = a;
		a = a->next;
	}
	return (max);
}

void	ft_tiny_sort(t_stack **a)
{
	t_stack	*max;

	max = ft_maxstack(*a);
	if (max->prev == NULL)
		ra_rb(a, 1, 1);
	else if (max->next != NULL)
		rra_rrb(a, 1, 1);
	if (!ft_stacksorted(*a))
		sa_sb(*a, 1, 1);
}
