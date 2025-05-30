/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:27:59 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/17 15:32:30 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char ***arr)
{
	int	i;

	i = 0;
	while (*arr[i])
	{
		free(*arr[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
