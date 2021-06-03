#!/bin/bash
echo "Enter number"
read n
for i in $(seq 1 10)
do
	echo "$n * $i = $((n * i))"
done
