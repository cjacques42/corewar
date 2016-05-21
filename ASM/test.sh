# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_bin.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 19:00:10 by cjacques          #+#    #+#              #
#    Updated: 2016/05/19 13:29:30 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo file: zork.s
./examples/asm zork.s >/dev/null
hexdump zork.cor > r1
cat r1
./asm zork.s >/dev/null
hexdump zork.cor > r2
cat r2
ret=$(diff -s r1 r2)
if [ "$ret" = "Files r1 and r2 are identical" ]
then
	echo "\033[32mOK\033[0m"
else
	echo "\033[31mKO\033[0m"
fi
rm r1 r2
./examples/asm -a zork.s > r1
cat r1
./asm -a zork.s > r2
cat r2
ret=$(diff -s r1 r2)
if [ "$ret" = "Files r1 and r2 are identical" ]
then
	echo "\033[32mOK\033[0m"
else
	echo "\033[31mKO\033[0m"
fi
#rm r1 r2
