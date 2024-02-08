/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:51:00 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:38 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"

/* ********************************FUNCTIONS********************************* */

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;

	s = (char *)b;
	while (len > 0)
		s[--len] = c;
	return (b);
}