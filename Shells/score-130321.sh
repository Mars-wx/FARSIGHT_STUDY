#!/bin/bash

SCORE=$1

if [ $# -ne 1 ]; then
	echo "invalid arguments"
	exit
fi

if ! expr $SCORE + 1 &>/dev/null ; then
	echo "not integer"
	exit
fi

if [ $SCORE -gt 100 ] || [ $1 -lt 0 ]; then
	echo "out of range"
	exit
fi

if [ $SCORE -ge 90 ]; then
	RESULT="A"
else
	if [ $SCORE -ge 80 ]; then
		RESULT="B"
	else
		if [ $SCORE -ge 70 ]; then
			RESULT="C"
		else
			if [ $SCORE -ge 60 ]; then
				RESULT="D"
			else
				RESULT="FAIL"
			fi
		fi
	fi
fi

echo $RESULT
