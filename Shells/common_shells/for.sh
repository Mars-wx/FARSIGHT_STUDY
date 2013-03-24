#!/bin/bash 

cd /home/james
filelist=`ls /home/james`
for file in $filelist
do
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
