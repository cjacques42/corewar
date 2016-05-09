/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoussay <stoussay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:48:04 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/09 14:16:07 by stoussay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short		char_to_short(unsigned char *str)
{
	short	result[2];

	result[0] = (short)str[0] << 8;
	result[1] = (short)str[1];
	return (result[0] + result[1]);
}
