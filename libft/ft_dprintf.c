/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:36:56 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/17 17:51:04 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dformat_check(va_list args, char format, int fd)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count = dprint_int(va_arg(args, int), fd);
	else if (format == 'u')
		count = dprint_uint(va_arg(args, unsigned int), fd);
	else if (format == 'x' || format == 'X')
		count = dprint_hex(va_arg(args, unsigned int), format, fd);
	else if (format == 's')
		count = dprint_str(va_arg(args, char *), fd);
	else if (format == 'c')
		count = dprint_char(va_arg(args, int), fd);
	else if (format == 'p')
		count = dprint_ptr(va_arg(args, unsigned long int), fd);
	else if (format == '%')
		count = dprint_prcnt(fd);
	return (count);
}

int	dprint_invalid(char c, char null_check, int *invalid, int fd)
{
	if (*invalid == 0 && null_check == 0)
		return (-1);
	*invalid = 1;
	return (dprint_char(c, fd));
}

int	dvalid_format(va_list args, const char *format, int i, int fd)
{
	int	fail_check;
	int	invalid;
	int count;

	count = 0;
	invalid = 0;
	while (format[++i])
	{
		fail_check = 0;
		if (format[i] == '%')
		{
			if (ft_memchr(FORMATS, format[i + 1], ft_strlen(FORMATS)))
				fail_check = dformat_check(args, format[i++ + 1], fd);
			else
				fail_check = dprint_invalid(format[i], format[i + 1], &invalid, fd);
		}
		else if (format[i] == '%' && format[i + 1] == 0)
			break ;
		else
			fail_check = dprint_char(format[i], fd);
		if (fail_check < 0)
			return (-1);
		count += fail_check;
	}
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	count = dvalid_format(args, format, -1, fd);
	va_end(args);
	return (count);
}
