#!/bin/bash 

I=10
j=10
if [ $I -gt $j ]
then 
	echo "i > j"
else
	if [ $I -eq $j ]
	then
		echo "i = j"
	else
		echo "j > i"
	fi
fi
