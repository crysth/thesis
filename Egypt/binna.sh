#!/bin/bash

# arg 1 = nomefile
# arg 2 = grandezza bin


frequenze=(`cat $1 | awk '{print $1}'`)
valori=(`cat $1 | awk '{print $2}'`)

bin_i=0
bin_f=$2
dim_bin=$2
j=0
istogramma[0]=0


for((i=0;i<${#frequenze[@]};i++)); do

	if [ ${valori[i]} -lt $bin_f ];
	then
		istogramma[$j]=$((istogramma[$j] + ${frequenze[i]}))
	else
		echo $bin_i $bin_f $((bin_f-bin_i)) ${istogramma[j]}

		while [ ${valori[i]} -ge $bin_f ]; do
			bin_i=$bin_f
			bin_f=$((bin_i+dim_bin**$((j+2))))
			j=$((j+1))
		done

		istogramma[$j]=${frequenze[i]}
	fi
done

	echo $bin_i $bin_f $((bin_f-bin_i)) ${istogramma[j]}


