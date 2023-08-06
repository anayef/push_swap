/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:54:28 by anayef            #+#    #+#             */
/*   Updated: 2023/08/06 11:26:17 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

static int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_within_int_limits(const char *str)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > (long long)INT_MAX + 1))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	has_invalid_sign_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == ' ')
		{
			int ret = write(2, "Error\n", 6);
		(void)ret; // Dummy variable to capture the return value
		return (1);
		}
		i++;
	}
	return (0);
}

int	handle_input_errors(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2 || has_duplicates(argc, argv))
	{
		int ret = write(2, "Error\n", 6);
		(void)ret; // Dummy variable to capture the return value
		return (1);
	}
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_within_int_limits(argv[i])
			|| has_invalid_sign_format(argv[i]))
		{
			int ret = write(2, "Error\n", 6);
		(void)ret; // Dummy variable to capture the return value
		return (1);
		}
		i++;
	}
	return (0);
}
