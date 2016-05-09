#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int main(int ac, char **av)
{
   int fd;
   char *buf;
   char *tmp;
   int i;
   int ret;

   i = 0;
   ret = 0;
   fd = open(av[1], O_RDONLY);
   buf = (char *)malloc(sizeof(char) * 256);
   tmp = (char *)malloc(sizeof(char) * 1);
   tmp[0] = '\0';
   while ((ret = read(fd, buf, 1)))
   {
       printf("%d", buf[i]);
       i++;
   }
  close(fd);
}
