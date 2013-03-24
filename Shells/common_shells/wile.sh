#!/bin/bash 

while read file
do 
	if [ $file = "#" ]
	then
		exit
	fi
	if ! [  -e $file ]
	then 
		echo "$file is not exists"
		continue
	fi

	if [ -L $file ]
	then 
		tput bold
		echo -n "$file "
		tput sgr0
		echo -n "is a "
		tput smso
		echo "link file"
		tput sgr0
	else
		if [ -f $file ]
		then 
			tput bold
			echo -n "$file "
			tput sgr0
			echo -n "is a "
			tput smso
			echo "regular file"
			tput sgr0
		else
			if [ -d $file ]
			then 
				tput bold
				echo -n "$file "
				tput sgr0
				echo -n "is a "
				tput smso
				echo "directory file"
				tput sgr0
			fi

		fi

	fi
done
