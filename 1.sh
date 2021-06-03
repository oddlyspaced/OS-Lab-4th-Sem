#!/bin/bash
echo "Enter 2 numbers"
read n1
read n2
if [ "$n1" -gt "$n2" ]
then
	x=$n1
else
	x=$n2
fi
echo "$x is larger"
