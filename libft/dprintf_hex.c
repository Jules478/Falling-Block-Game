/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:42 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/17 17:45:08 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dhex_length(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	dhex_write(unsigned int n, char format, int fail_check, int fd)
{
	if (n >= 16)
	{
		fail_check = dhex_write(n / 16, format, fail_check, fd);
		if (fail_check < 0)
			return (-1);
		fail_check = dhex_write(n % 16, format, fail_check, fd);
		if (fail_check < 0)
			return (-1);
	}
	else
	{
		if (n <= 9)
			fail_check = dprint_char((n + '0'), fd);
		else
		{
			if (format == 'x')
				fail_check = dprint_char((n - 10 + 'a'), fd);
			if (format == 'X')
				fail_check = dprint_char((n - 10 + 'A'), fd);
		}
	}
	if (fail_check < 0)
		return (-1);
	return (dhex_length(n));
}

int	dprint_hex(unsigned int n, char format, int fd)
{
	int	count;

	count = 0;
	if (n == 0)
		return (dprint_char('0', fd));
	count = dhex_write(n, format, 1, fd);
	return (count);
}
