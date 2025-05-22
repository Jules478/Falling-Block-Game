/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:01:52 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/17 17:47:36 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	duintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_dunsignitoa(unsigned int n, int len)
{
	char				*str;
	unsigned int		result;

	result = n;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len--)
	{
		str[len] = (result % 10) + 48;
		result /= 10;
	}
	return (str);
}

int	dprint_uint(unsigned int n, int fd)
{
	char	*number;
	int		count;

	count = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	number = ft_dunsignitoa(n, duintlen(n));
	count = dprint_str(number, fd);
	free(number);
	return (count);
}
