# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_test.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/13 17:47:02 by cjacques          #+#    #+#              #
#    Updated: 2016/05/13 19:07:16 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
file="test.s"
make all >/dev/null
	echo file: $file
	./examples/asm $file
	hexdump `basename $file .s`.cor > r1
	./asm $file
	hexdump `basename $file .s`.cor > r2
	ret1=$(diff -s r1 r2)
	if [ "$ret1" = "Files r1 and r2 are identical" ]
	then
		echo "\033[32mOK\033[0m"
	else
		echo "\033[31mKO\033[0m"
	fi
	./examples/asm -a $file > r1
	./asm -a $file > r2
	ret2=$(diff -s r1 r2)
	if [ "$ret2" = "Files r1 and r2 are identical" ]
	then
		echo "\033[32mOK\033[0m"
	else
		echo "\033[31mKO\033[0m"
	fi
	rm r1 r2
