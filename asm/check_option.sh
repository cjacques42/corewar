# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 12:20:01 by cjacques          #+#    #+#              #
#    Updated: 2016/05/12 19:06:09 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make all >/dev/null
for file in examples/*.s
do
	echo file: $file
	./examples/asm -a $file > r1
	./asm -a $file > r2
	diff -s r1 r2
	rm r1 r2
#	read -n1 -r -p "Press key to continue..." key
done
