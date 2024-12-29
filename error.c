/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:51:15 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/29 11:54:12 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_list **a, t_list **b)
{
	if (a)
		ft_lstclear(a, free);
	if (b)
		ft_lstclear(b, free);
	write(2, "Error\n", 6);
    exit(1);
	return;
}

int    is_valid_number(const char *str, long *num)
{
    int     i;
    long    temp;

    i = 0;
    if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    temp = ft_atoi(str);
    if (temp > INT_MAX || temp < INT_MIN)
        return (0);
    *num = temp;
    return (1);
}

int	has_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *)stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
