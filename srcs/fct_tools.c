/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:13:00 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/17 18:41:38 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!s2[i])
			return (1);
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s2[i] != '\0')
		return (1);
	return (0);
}*/

int		ft_failure(t_list *l, char *msg)
{
	ft_putstr(msg);
	if (l != NULL)
		key_free(l);
	return (1);
}

/*int		how_long(int nb, int size)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / size;
		i++;
	}
	return (i);
}*/

void	ft_swap_double(double *n1, double *n2)
{
	double n3;

	n3 = *n1;
	*n1 = *n2;
	*n2 = n3;
}

void	ft_swap(int *n1, int *n2)
{
	int n3;

	n3 = *n1;
	*n1 = *n2;
	*n2 = n3;
}

int ft_atoi_size(const char *str, int *size)
{
    int i;
    int nb;
    long sign;

    i = 0;
    nb = 0;
    sign = 0;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    if (str[i] == '-')
        sign++;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    *size = i;
    if (sign == 1)
        return (-nb);
    return (nb);
}
