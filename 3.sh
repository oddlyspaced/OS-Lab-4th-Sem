#!/bin/bash
echo "Enter number"
read n
m=1
for i in $(seq 1 $n)
do
	m=$((m * i))
done
echo "Factorial is $m"
