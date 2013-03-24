#!/bin/bash 

if [ $# -ne 1 ]
then
	echo "arg error !"
	exit
fi

if [ -L $1 ]
then 
	tput bold
	echo -n "$1 "
	tput sgr0
	echo -n "is a "
	tput smso
	echo "link file"
	tput sgr0
else
	if [ -f $1 ]
	then 
		tput bold
		echo -n "$1 "
		tput sgr0
		echo -n "is a "
		tput smso
		echo "regular file"
		tput sgr0
	else
		if [ -d $1 ]
		then 
			tput bold
			echo -n "$1 "
			tput sgr0
			echo -n "is a "
			tput smso
			echo "directory file"
			tput sgr0
		fi

	fi

fi
