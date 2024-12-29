/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:06:13 by kokamoto          #+#    #+#             */
/*   Updated: 2024/12/29 13:21:34 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * 3);
	if (!arr)
		error_exit(a, NULL);
	arr[0] = *(int *)(*a)->content;
	arr[1] = *(int *)(*a)->next->content;
	arr[2] = *(int *)(*a)->next->next->content;
	if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		sa(a);
		rra(a);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		ra(a);
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		sa(a);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
	{
		sa(a);
		ra(a);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
		rra(a);
	free(arr);
}

void	sort_five(t_list **a, t_list **b)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size - 3)
	{
		pb(a, b);
		i++;
	}
	sort_three(a);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}

void	sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	long	num;
	int		*content;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	while (--argc)
	{
		if (!is_valid_number(argv[argc], &num) || has_duplicate(a, num))
			error_exit(&a, &b);
		content = (int *)malloc(sizeof(int));
		if (!content)
			error_exit(&a, &b);
		*content = num;
		ft_lstadd_front(&a, ft_lstnew(content));
	}
	if (!is_sorted(a))
		sort(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
