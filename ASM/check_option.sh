# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 12:20:01 by cjacques          #+#    #+#              #
#    Updated: 2016/05/16 17:29:50 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for file in examples/*.s
do
	echo "file: $file"
	./examples/asm -a $file > r1
	./asm -a $file > r2
	ret=$(diff -s r1 r2)
	if [ "$ret" = "Files r1 and r2 are identical" ]
	then
		echo "\033[32mOK\033[0m"
	else
		echo "\033[31mKO\033[0m"
	fi
	rm r1 r2
	#read -n1 -r -p "Press key to continue..." key
done
