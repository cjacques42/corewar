/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:48:04 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/02 14:37:23 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_to_int(unsigned char *str)
{
	int		result[4];

	result[0] = (int)str[0] << 24;
	result[1] = (int)str[1] << 16;
	result[2] = (int)str[2] << 8;
	result[3] = (int)str[3];
	return (result[0] + result[1] + result[2] + result[3]);
}
