/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:10:27 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/09 19:21:50 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*create_init_cmd(int i)
{
	t_cmd	*cmd;

	if ((cmd = (t_cmd*)malloc(sizeof(*cmd))) == NULL)
		exit(0);
	cmd->str = ft_strdup(g_op_tab[i].label);
	cmd->addr = g_data.addr;
	cmd->nbr = i;
	cmd->arg = NULL;
	return (cmd);
}

int		check_mnemo(char *line, t_list **cmds, t_list **lbls)
{
	int		i;
	int		len;
	t_cmd	*cmd;

	(void)lbls;
	i = 0;
	while (g_op_tab[i].label != NULL)
	{
		len = ft_strlen(g_op_tab[i].label);
		if (ft_strncmp(g_op_tab[i].label, line, len) == 0 && ft_isspace(line[len]))
		{
			cmd = create_init_cmd(i);
			ft_lstaddback(cmds, ft_lstnew((void*)cmd, sizeof(cmd)));
			printf("%s\n", g_op_tab[i].label);
			return (len);
		}
		i++;
	}
	return (-1);
}

char	*is_selector(char *line, int *sep)
{
	*sep = FALSE;
	while (*line)
	{
		if (*line == SEPARATOR_CHAR)
		{
			if (*sep == TRUE)
				ft_exit_mess(13);
			*sep = TRUE;
		}
		else if (ft_isspace(*line) != 0)
			return (line);
		line++;
	}
	return (NULL);
}

int		check_arg(char *line, t_list **cmds)
{
	int		i;
	int		sep;
	char	*tmp;
	t_list	*args;

	(void)cmds;
	i = 0;
	while (line[i])
	{
		if ((tmp = is_selector(line + i, &sep)) != NULL || i == 0)
			sep = TRUE;
		printf("sep = %d\n", sep);
		if (*tmp == 'r' && sep == TRUE)
			line = check_reg(line, &args);
		else if (*tmp == DIRECT_CHAR && sep == TRUE)
			line = check_dir(line, &args);
		else if ((*tmp == LABEL_CHAR || ft_isdigit(*tmp)) && sep == TRUE)
			line = check_ind(line, &args);
		else if (sep == FALSE && ft_empty(line) == 0)
			ft_exit_mess(12);
		i++;
	}
	printf("-------------------------------------\n");
	ft_add_args_to_cmd(cmds, args);
	return (0);
}

int		check_line(char *line, t_list **cmds, t_list **lbls)
{
	int		ret;

	(void)lbls;
	if ((ret = check_mnemo(line, cmds, lbls)) > -1)
	{
		line += ret + 1;
		line = ft_strtrim(line);
		check_arg(line, cmds);
		return (1);
	}
	return (0);
}
