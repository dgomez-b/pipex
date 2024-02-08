/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:20:18 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/02/08 19:32:22 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/// @brief Frees a matrix
/// @param mat matrix to be freed
void	freemat(void **mat)
{
	unsigned int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}
