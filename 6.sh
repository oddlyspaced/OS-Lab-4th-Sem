#!/bin/bash
echo "Enter number"
read num
sum=0
while read -n1 digit; do
	sum=$(($sum + $digit))
done < <(echo -n "$num")
echo "Sum of digits is $sum"
