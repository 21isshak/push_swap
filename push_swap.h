/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:58:13 by iskaraag          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:59 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				position;
	int				totop_rr;
	int				p_price;
	int				p_mode;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

//error_handler.c
void			ft_avfree(char **av);
void			ft_stackfree(t_stack **stack);
void			ft_error(t_stack **stack, char **av, bool flag_av);
//makestack.c
long long int	ft_atol(const char *str);
void			ft_makestack(t_stack **stack, char **av, bool flag_av);
//stack_utils.c
t_stack			*ft_lastnode(t_stack *head);
bool			ft_stacksorted(t_stack *stack);
int				ft_stacklength(t_stack *stack);
//tiny_sort.c
t_stack			*ft_maxstack(t_stack *a);
void			ft_tiny_sort(t_stack **a);
//commands.c
void			sa_sb(t_stack *stack, bool printit, bool sa);
void			ss(t_stack *a, t_stack *b);
void			pa_pb(t_stack **tar, t_stack **dest, bool pa);
//commands_r.c
void			ra_rb(t_stack **stack, bool printit, bool ra);
void			rr(t_stack **a, t_stack **b);
void			rra_rrb(t_stack **stack, bool printit, bool rra);
void			rrr(t_stack **a, t_stack **b);
//push_swap.c
void			push_it(t_stack **a, t_stack **b);
void			final_setittop(t_stack **a, t_stack *max);
void			push_swap(t_stack **a, t_stack **b);
//push_swap_utils.c
int				ft_max(int a, int b);

#endif
