# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_cor.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacques <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/13 10:10:40 by cjacques          #+#    #+#              #
#    Updated: 2016/05/13 10:13:47 by cjacques         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for file in examples/*.s
do
	echo file: $file
	./examples/asm $file
#	read -n1 -r -p "Press key to continue..." key
done
