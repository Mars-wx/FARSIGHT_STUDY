#!/bin/bash 

i=0
nu=20121011
ch=100
ma=50
en=90

while [ $i -lt 10 ]
do
	echo "james$i:$nu:$ch:$ma:$en">> stu.info
	ch=`expr $ch - 2`
	ma=`expr $ma + 2`
	en=`expr $ch - 1`
	nu=`expr $nu + 1`
	i=`expr $i + 1`

done
