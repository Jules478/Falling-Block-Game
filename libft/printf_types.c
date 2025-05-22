/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:33:37 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/18 13:26:44 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	count = write(1, str, ft_strlen(str));
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_prcnt(void)
{
	return (write(1, "%", 1));
}

int	print_int(int n)
{
	int		length;
	char	*number;

	length = 0;
	number = ft_itoa(n);
	length = print_str(number);
	free(number);
	return (length);
}
