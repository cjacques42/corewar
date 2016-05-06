/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 09:55:43 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 12:32:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			token(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(LABEL_CHARS, str[i]) != NULL)
			;
	}
	return (0);
}

t_header	*init_header(void)
{
	t_header	*header;

	header = (t_header*)malloc(sizeof(header));
	header->magic = COREWAR_EXEC_MAGIC;
	printf("\nmagic = %u\n", header->magic);
	printf("\nmagic = %08x\n", header->magic);
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	header->prog_size = 0;
	ft_bzero(header->comment, COMMENT_LENGTH + 1);
	return (header);
}

int			header_cmp(char *str, char *line, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(line, '"') + 1;
	while (tmp[i] && tmp[i] != '"')
		i++;
	ft_strcpy(str, tmp);
	ft_printf("name = %s\nlen = %d\n", tmp, i);
	if (i > len)
		return (1);
	return (0);
}

void		start_lex(int fd)
{
	char		*line;
	t_header	*header;
	int			name;
	int			comment;

	name = 0;
	comment = 0;
	header = init_header();
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, NAME_CMD_STRING) != NULL)
		{
			header_cmp(header->prog_name, line, PROG_NAME_LENGTH);
//			name++;
		}
		else if (ft_strstr(line, COMMENT_CMD_STRING) != NULL)
		{
			header_cmp(header->comment, line, COMMENT_LENGTH);
//			comment++;
		}
		else
			ft_printf("!\n");
//		if (name > 1 || comment > 1)
//			ft_printf("Error Header !!!!!!\n");
	}
	ft_printf("%s\n", header->prog_name);
	ft_putstr(header->comment);
}
