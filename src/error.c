/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:20:46 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/02/08 19:32:20 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/// @brief Prints the error into stdout and exits program with errno value
void	error(void)
{
	perror("\e[31mError");
	exit (errno);
}
