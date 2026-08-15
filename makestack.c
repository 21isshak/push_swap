/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:38:45 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:30 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_numcheck(char *str)
{
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (false);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '\0')
		return (true);
	return (false);
}

static bool	ft_ifrepeated(t_stack *a, int num)
{
	if (a == NULL)
		return (0);
	if (a->value == num)
		return (1);
	return (ft_ifrepeated(a->next, num));
}
// int	ft_ifrepeated(t_stack *stack, int nm)
// {
// 	if (stack == NULL)
// 		return (0);
// 	while (stack)
// 	{
// 		if (stack->value == nm)
// 			return (1);
// 		stack = stack->next;
// 	}
// 	return (0);
// }

static int	ft_addnode(t_stack **a, int value)
{
	t_stack	*current;
	t_stack	*last;

	if (a == NULL)
		return (1);
	current = malloc(sizeof(t_stack));
	if (!current)
		return (1);
	current->value = value;
	current->next = NULL;
	if (*a == NULL)
	{
		current->prev = NULL;
		*a = current;
	}
	else
	{
		last = ft_lastnode(*a);
		last->next = current;
		current->prev = last;
	}
	return (0);
}
// void	ft_addnode(t_stack **stack, int value)
// {
// 	t_stack	*current;
// 	t_stack	*last;

// 	if (stack == NULL)
// 		return ;
// 	current = malloc(sizeof(t_stack));
// 	if (current == NULL)
// 		return ;
// 	current->next = NULL;
// 	current->value = value;
// 	if (*stack == NULL)
// 	{
// 		*stack = current;
// 		current->prev = NULL;
// 	}
// 	else
// 	{
// 		last = ft_lastnode(*stack);
// 		last->next = current;
// 		current->prev = last;
// 	}
// }

long long int	ft_atol(const char *str)
{
	int				sign;
	long long int	val;

	sign = 1;
	val = 0;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + *str - '0';
		str++;
		if (val == LLONG_MAX / 10 && sign == -1 && *str == '8')
			return (LLONG_MIN);
	}
	return (val * sign);
}

void	ft_makestack(t_stack **stack, char **av, bool flag_av)
{
	int				i;
	long long int	nbr;

	i = 0;
	while (av[i])
	{
		if (!ft_numcheck(av[i]))
			ft_error(stack, av, flag_av);
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			ft_error(stack, av, flag_av);
		if (ft_ifrepeated(*stack, (int)nbr))
			ft_error(stack, av, flag_av);
		if (ft_addnode(stack, (int)nbr))
			ft_error(stack, av, flag_av);
		i++;
	}
	if (flag_av)
		ft_avfree(av);
}
