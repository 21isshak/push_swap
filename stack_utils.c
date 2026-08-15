/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:47:25 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:03:07 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lastnode(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

bool	ft_stacksorted(t_stack *stack)
{
	int	tmp;

	tmp = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value <= tmp)
			return (0);
		tmp = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	ft_stacklength(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
