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
	{
		ft_putstr_fd("Usage: ./examples/asm [-a] <sourcefile.s>\
\n    -a : Instead of creating a .cor file, outputs a stripped and \
annotated version of the code to the standard output\n", 2);
	}
	ft_puterr("\n");
	exit(0);
}
