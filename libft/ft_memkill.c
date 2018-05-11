/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memkill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:01:28 by vordynsk          #+#    #+#             */
/*   Updated: 2018/03/05 11:01:30 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_memkill(char **res, int i)
{
	while (i >= 0)
		ft_strdel(&res[i--]);
	free(res);
	res = NULL;
}