/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 16:53:42 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/15 17:31:41 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_char(t_print *data)
{
	char	c;

	c = va_arg(data->args, int);
	data->char_count += write(1, &c, 1);
}
