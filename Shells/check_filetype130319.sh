#!/bin/bash 

i=0

read -p "Please input your filename: " FILE

for VALUE in $FILE
do 
	if [ -f $VALUE ]; then
		echo ---common files---
	else
		if [ -L $VALUE ]; then
			echo ---linked files---
		else
			if [ -S $VALUE ]; then
				echo ---socket files---
			else
				if [ -p $VALUE ]; then
					echo ---pipe files---
				else
					echo ---other files---
				fi
			fi
		fi
	fi
	echo $VALUE
	i=`expr $i + 1`
done

if [ $i -eq 0 ]; then
	echo "The directory is not exit"
else
	echo $i
fi
