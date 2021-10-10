#!/bin/bash

ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
if [[ $1 -lt 0 ]]; then 
	var1=$(( 0 - $1 ))
else
	var1=$1
fi
if [[ $2 -lt 0 ]]; then 
	var2=$(( 0 - $2 ))
else
	var2=$2
fi

if [[ $2 -lt 0 ]]; then
	n=$(( $var1 - $var2 - 1 ))
else
	n=$(( $var1 + $var2 + 1 ))
fi

echo "taille = $n"

./push_swap $ARG | ./checker $ARG ; echo -e "\n-=-=-=-=-=-=-=-=-=-=-=-=-\n" ; ./push_swap $ARG | wc -l
