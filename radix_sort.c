/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:05:01 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/29 13:09:33 by kokamoto         ###   ########.fr       */
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

// 基数ソートのメイン関数
void    radix_sort(t_list **a, t_list **b)
{
    int     max_bits;
    int     i;
    int     j;
    int     size;
    t_list  *current;
    int     max_num;

    size = ft_lstsize(*a);
    if (size <= 3)
    {
        sort_three(a);
        return;
    }

    // スタックを正規化
    normalize_stack(a);

    // 最大ビット数を計算
    current = *a;
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

    // 基数ソート
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((*(int *)(*a)->content >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}
