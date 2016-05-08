#include "asm.h"

void	parse_body(int fd)
{
	char	*line;

	printf("\n");
	while (read_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
}
