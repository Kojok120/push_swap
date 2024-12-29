/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:05:01 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/29 13:19:08 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// インデックスを正の数に変換する
int    get_min(t_list *stack)
{
    int     min;
    t_list  *current;

    min = *(int *)stack->content;
    current = stack->next;
    while (current)
    {
        if (*(int *)current->content < min)
            min = *(int *)current->content;
        current = current->next;
    }
    return (min);
}

static int    get_max(t_list *stack)
{
    t_list  *current;
    int     max_num;
    int     max_bits;

    current = stack;
    max_num = *(int *)current->content;
    while (current)
    {
        if (*(int *)current->content > max_num)
            max_num = *(int *)current->content;
        current = current->next;
    }
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void normalize_stack(t_list **stack)
{
    t_list  *current;
    int     min;

    min = get_min(*stack);
    if (min < 0)
    {
        current = *stack;
        while (current)
        {
            *(int *)current->content -= min;
            current = current->next;
        }
    }
}

void    radix_sort(t_list **a, t_list **b)
{
    int     max_bits;
    int     size;
    int     i;
    int     j;

    size = ft_lstsize(*a);
    normalize_stack(a);
    max_bits = get_max_bits(*a);
    i = -1;
    while (++i < max_bits)
    {
        j = -1;
        while (++j < size)
        {
            if ((*(int *)(*a)->content >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (*b)
            pa(a, b);
    }
}
