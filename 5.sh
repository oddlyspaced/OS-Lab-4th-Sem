#!/bin/bash
check_prime () {
	for ii in $(seq 2 $(($1 / 2)))
	do
		if [ $(( $1 % $ii)) -eq 0 ]
		then
			# factor found (not a prime)
			return 0
		fi
	done
	return 1
}

echo "Enter number 1"
read a
echo "Enter number 2"
read b

for i in $(seq $a $b)
do
	check_prime $i
	if [ $? -eq 1 ]
	then
		echo $i
	fi
done
