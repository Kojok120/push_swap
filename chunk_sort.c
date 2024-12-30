/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:26:31 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/30 13:41:08 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_to_b(t_list **a, t_list **b, int min, int max)
{
	if (*(int *)(*a)->content >= min && *(int *)(*a)->content <= max)
	{
		pb(a, b);
		if (*(int *)(*b)->content < (min + max) / 2)
			rb(b);
	}
	else
		ra(a);
}

int	has_numbers_in_range(t_list *stack, int min, int max)
{
	int	num;

	while (stack)
	{
		num = *(int *)stack->content;
		if (num >= min && num <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_max_position(t_list *stack)
{
	t_list	*current;
	int		max;
	int		max_pos;
	int		pos;

	current = stack;
	max = *(int *)current->content;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (*(int *)current->content > max)
		{
			max = *(int *)current->content;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

void	move_max_to_top(t_list **stack)
{
	int	max_pos;
	int	size;

	size = ft_lstsize(*stack);
	max_pos = find_max_position(*stack);
	if (max_pos <= size / 2)
	{
		while (max_pos--)
			rb(stack);
	}
	else
	{
		while (max_pos++ < size)
			rrb(stack);
	}
}

void	chunk_sort(t_list **a, t_list **b)
{
	int	size;
	int	chunk_size;
	int	i;
	int	min;
	int	max;

	size = ft_lstsize(*a);
	chunk_size = size / 3;
	i = -1;
	while (++i < 3)
	{
		min = i * chunk_size;
		max = (i + 1) * chunk_size;
		while (has_numbers_in_range(*a, min, max))
			push_chunk_to_b(a, b, min, max);
	}
	while (*b)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}
