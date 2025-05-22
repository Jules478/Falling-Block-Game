/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:07:23 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/17 17:52:45 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dptr_length(unsigned long int n)
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

int	dptr_write(unsigned long int n, int fail_check, int fd)
{
	if (n >= 16)
	{
		fail_check = dptr_write(n / 16, fail_check, fd);
		if (fail_check < 0)
			return (-1);
		fail_check = dptr_write(n % 16, fail_check, fd);
		if (fail_check < 0)
			return (-1);
	}
	else
	{
		if (n <= 9)
			fail_check = dprint_char((n + '0'), fd);
		else
			fail_check = dprint_char((n - 10 + 'a'), fd);
	}
	if (fail_check < 0)
		return (-1);
	return (dptr_length(n));
}

int	dprint_ptr(unsigned long int n, int fd)
{
	int	len;
	int	check;

	check = 0;
	if (n == 0)
		return (dprint_str("(nil)", fd));
	len = 0;
	len += dprint_str("0x", fd);
	if (len < 0)
		return (-1);
	check = dptr_write(n, 1, fd);
	if (check < 0)
		return (-1);
	len += check;
	return (len);
}
