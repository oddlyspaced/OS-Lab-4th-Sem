#!/bin/bash
echo "Enter sentence"
read sent
counter=0
for word in $sent
do
	counter=$(($counter + 1))
done
echo "$counter word(s)"
