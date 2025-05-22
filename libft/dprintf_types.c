/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:33:37 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/18 13:27:00 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dprint_str(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	count = write(fd, str, ft_strlen(str));
	return (count);
}

int	dprint_char(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	dprint_prcnt(int fd)
{
	return (write(fd, "%", 1));
}

int	dprint_int(int n, int fd)
{
	int		length;
	char	*number;

	length = 0;
	number = ft_itoa(n);
	length = dprint_str(number, fd);
	free(number);
	return (length);
}
