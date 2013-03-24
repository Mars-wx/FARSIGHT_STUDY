#!/bin/bash

read VALUE

VALUE=`expr $VALUE / 10`

case $VALUE in
	10)
		echo A
		;;
	9)
		echo A
		;;
	8)
		echo B
		;;
	7)
		echo C
		;;
	6)
		echo D
		;;
	*)
		echo FAIL
		;;
esac
