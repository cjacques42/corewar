# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_bin.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/12 19:00:10 by cjacques          #+#    #+#              #
#    Updated: 2016/05/12 19:11:56 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

make all >/dev/null
for file in examples/*.s
do
	echo file: $file
	./examples/asm $file
	hexdump examples/`basename $file .s`.cor > r1
	./asm $file
	hexdump examples/`basename $file .s`.cor > r2
	diff -s r1 r2
	rm r1 r2
	read -n1 -r -p "Press key to continue..." key
done
