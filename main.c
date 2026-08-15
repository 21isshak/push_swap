/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:58:06 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:11 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_error(NULL, NULL, 0);
	av++;
	if (ac == 2)
	{
		av = ft_split(av[0], ' ');
		if (!av)
			return (1);
	}
	ft_makestack(&a, av, ac == 2);
	if (!ft_stacksorted(a))
	{
		if (ft_stacklength(a) == 2)
			sa_sb(a, 1, 1);
		else if (ft_stacklength(a) == 3)
			ft_tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	ft_stackfree(&a);
}
