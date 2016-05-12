/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:27:42 by stoussay          #+#    #+#             */
/*   Updated: 2016/05/11 20:18:12 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_processes *current)
{
	int val;
	int rg;

	rg = g_data->vm[current->pc + 2];
	val = current->reg[rg - 1] % 256;
	write(1, &rg, 1);
	current->pc += 3;
	current->pc %= MEM_SIZE;
}
