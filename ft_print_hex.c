/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 17:00:11 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/16 15:25:50 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static void	ft_itohex(t_print *data, unsigned long nb, int caps);

void	ft_print_nbr_hex(t_print *data, int caps)
{
	unsigned int	nb;

	nb = va_arg(data->args, unsigned int);
	if (caps == 1)
		ft_itohex(data, nb, 0);
	else if (caps == 0)
		ft_itohex(data, nb, 32);
}

void	ft_print_ptr_hex(t_print *data)
{
	unsigned long	ptr;

	ptr = va_arg(data->args, unsigned long);
	data->char_count += write(1, "0x", 2);
	ft_itohex(data, ptr, 32);
}

static void	ft_itohex(t_print *data, unsigned long nb, int caps)
{
	if (nb <= 9)
	{
		nb = nb + 48;
		data->char_count += write(1, &nb, 1);
	}
	else if (nb < 16)
	{
		nb = nb + 55 + caps;
		data->char_count += write(1, &nb, 1);
	}
	else
	{
		ft_itohex(data, nb / 16, caps);
		ft_itohex(data, nb % 16, caps);
	}
}
