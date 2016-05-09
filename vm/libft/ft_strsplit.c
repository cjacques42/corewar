/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:15:37 by jcornill          #+#    #+#             */
/*   Updated: 2015/11/28 13:22:31 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		part_two(char const *s, char c, int tab[3], char **result)
{
	while (s[tab[0]] == c)
		tab[0]++;
	if (!s[tab[0]])
		return ;
	result[tab[2]][tab[1]] = s[tab[0]];
	tab[1]++;
	tab[0]++;
}

static void		part_one(int tab[3])
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
}

static int		part_three(int tab[3], char **r, char const *s)
{
	r[tab[2]][tab[1]] = 0;
	tab[2]++;
	if (!(r[tab[2]] = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	tab[1] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		tab[3];

	if (!s || !(r = (char **)malloc(sizeof(char) * (ft_strlen(s) + 1) * 25)))
		return (NULL);
	part_one(tab);
	if ((r[tab[2]] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[tab[0]])
	{
		part_two(s, c, tab, r);
		if (s[tab[0]] == c)
			if (!(part_three(tab, r, s)))
				return (NULL);
	}
	if (tab[0] == 0)
		r[0] = NULL;
	if (s[tab[0] - 1] == c)
		r[tab[2]] = 0;
	else
		r[tab[2] + 1] = 0;
	return (r);
}
