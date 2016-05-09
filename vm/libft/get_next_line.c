/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 10:32:29 by stoussay          #+#    #+#             */
/*   Updated: 2016/04/24 18:38:30 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strend(char *str, int start)
{
	while (str[start])
		start++;
	return (start);
}

char	*ft_read(char *swap, size_t fd)
{
	size_t			ret;
	char			*buf;
	char			*tmp;

	ret = 0;
	buf = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(swap, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strdup(swap);
		free(swap);
		swap = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (swap);
}

int		get_next_line(int const fd, char **line)
{
	static char		*swap = NULL;
	char			*buf;
	size_t			start;

	buf = ft_strnew(0);
	if (fd == -1 || read(fd, buf, 0) == -1 || !line)
		return (-1);
	free(buf);
	(!swap) ? (swap = ft_strnew(0)) : (NULL);
	swap = ft_read(swap, fd);
	if (ft_strchr(swap, '\n'))
	{
		start = 0;
		while (swap[start] != '\n')
			start++;
		*line = ft_strsub(swap, 0, start);
		swap = ft_strsub(swap, start + 1, ft_strend(swap, start));
		return (1);
	}
	if (swap[0] != '\0' && (*line = ft_strdup(swap)))
	{
		ft_bzero(swap, ft_strlen(swap));
		return (1);
	}
	return (0);
}
