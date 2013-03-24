#!/bin/bash 

#get data

SCORE=$1

# check data

if [ $# -ne 1 ]
then 
	echo "invalid arguments!"
	exit
fi
if ! expr $SCORE + 1 &>/dev/null
then
	echo "not integer"
	exit
fi
if [ $SCORE -gt 100 ] || [ $SCORE -lt 0 ]
then 
	echo "out of range"
	exit
fi

#process data

if [ $SCORE -ge 60 ]
then
	if [ $SCORE -ge 70 ]
	then 
		if [ $SCORE -ge 80 ]
		then
			if [ $SCORE -ge 90 ]
			then
				RESULT="A"
			else
				RESULT="B"
			fi
		else
			RESULT="C"
		fi
	else
		RESULT="D"
	fi
else
	RESULT="FAIL"
fi

#output data 
echo $RESULT
