#include "asm.h"

void	ft_exit_error(t_error err, char *str)
{
	if (err == ER_OPEN)
	{
		ft_puterr("Can't read source file ");
		ft_puterr(str);
	}
	else if (err == ER_CLOSE)
	{
		ft_puterr("Can't close source file ");
		ft_puterr(str);
	}
	else if (err == ER_FORMAT)
		ft_puterr("Can't open this file, extention isn't .s");
	else if (err == ER_EMPTY)
		ft_puterr("Usage: ./examples/asm [-a] <sourcefile.s>\
\n    -a : Instead of creating a .cor file, outputs a stripped and \
annotated version of the code to the standard output\n");
	ft_puterr("\n");
	exit(0);
}

void	ft_exit_mess(int errno)
{
	ft_puterr("Error at line ");
	ft_putnbr_fd(g_data.line, 2);
	ft_puterr(": ");
	ft_puterr(g_err[errno].str);
	ft_puterr("\n");
	exit(1);
}
