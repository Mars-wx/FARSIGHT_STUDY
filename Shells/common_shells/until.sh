#!/bin/bash 

i=10

until [ $i -lt 0 ]  
do 
	echo $i
	i=`expr $i - 1`
done
