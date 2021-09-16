/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:41:04 by rarihet           #+#    #+#             */
/*   Updated: 2019/12/06 23:16:35 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	manage_isspace(const char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	sign = 0;
	nb = 0;
	while (manage_isspace(str, i) == 1)
		i++;
	if (str[i] == '-')
		sign++;
	if (str[i] == '+')
		i++;
	while (str[i + sign] >= '0' && str[i + sign] <= '9')
	{
		nb = nb * 10 + str[i + sign] - 48;
		i++;
	}
	if (sign == 1)
		return ((int)nb * -1);
	return ((int)nb);
}
