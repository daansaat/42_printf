/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_nbr_unsigned.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 17:00:14 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/16 14:24:14 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static void	ft_putnbr(t_print *data, unsigned int nb);

void	ft_print_nbr(t_print *data)
{
	int		nb;

	nb = va_arg(data->args, int);
	if (nb < 0)
	{
		data->char_count += write(1, "-", 1);
		nb = nb * -1;
	}
	ft_putnbr(data, nb);
}

void	ft_print_nbr_unsigned(t_print *data)
{
	unsigned int	nb;

	nb = va_arg(data->args, unsigned int);
	ft_putnbr(data, nb);
}

static void	ft_putnbr(t_print *data, unsigned int nb)
{
	if (nb <= 9)
	{
		nb = nb + 48;
		data->char_count += write (1, &nb, 1);
	}
	else
	{
		ft_putnbr(data, nb / 10);
		ft_putnbr(data, nb % 10);
	}
}
